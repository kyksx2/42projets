#!/bin/bash
set -e

echo "=== Debut de l'initialisation de MariaDB ==="

if [ ! -f "/var/lib/mysql/ibdata1" ]; then
    echo "Premiere initialisation de MariaDB..."
    
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

mysqld --user=mysql --datadir=/var/lib/mysql & #--skip-networking --skip-grant-tables &
MYSQL_PID=$!

sleep 3
# for i in {1..30}; do
#     if mysqladmin ping --silent 2>/dev/null; then
#         echo "MariaDB est pret !"
#         break
#     fi
#     echo "Tentative $i/30..."
#     sleep 1
# done

# if ! mysqladmin ping --silent 2>/dev/null; then
#     echo "ERREUR : MariaDB n'a pas demarrage correctement"
#     exit 1
# fi

echo "Configuration de la base de donnees..."

mysql -u root -p${SQL_ROOT_PASSWORD} <<EOF

CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO '${SQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';
DELETE FROM mysql.user WHERE User='';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
FLUSH PRIVILEGES;
EOF

echo "Arret de l'instance temporaire..."
kill $MYSQL_PID
wait $MYSQL_PID 2>/dev/null || true

sleep 1

echo "Demarrage de MariaDB..."
exec mysqld --user=mysql --datadir=/var/lib/mysql
