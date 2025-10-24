[mysqld]

port                    = 3306
user                    = mysql
pid-file                = /run/mysqld/mysqld.pid
socket                  = /run/mysqld/mysqld.sock
basedir                 = /usr
datadir                 = /var/lib/mysql
tmpdir                  = /tmp
bind-address            = 0.0.0.0
character-set-server    = utf8mb4
collation-server        = utf8mb4_general_ci