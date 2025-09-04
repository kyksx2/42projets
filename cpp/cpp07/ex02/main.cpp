#include <iostream>
#include "Array.hpp"

// #define MAX_VAL 10   // réduit à 10 pour affichage lisible

int main() {
    Array<std::string> tab(3);

    tab[0] = "je";
    tab[1] = "suis";
    tab[2] = "Kyllian";

    try {
        std::cout << tab[2] << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "--- changement d'ellement ---" << std::endl;
    tab[2] = "Alexis";
    try {
        std::cout << tab[2] << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}

// int main(void)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));

//     std::cout << "Initialisation des tableaux:" << std::endl;
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand() % 100; // borné pour lisibilité
//         numbers[i] = value;
//         mirror[i] = value;
//         std::cout << "numbers[" << i << "] = " << numbers[i] 
//                   << " | mirror[" << i << "] = " << mirror[i] << std::endl;
//     }

//     std::cout << "\nTest de copie..." << std::endl;
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//         std::cout << "Copie réussie." << std::endl;
//     }

//     std::cout << "\nVérification d'égalité avec mirror:" << std::endl;
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "Erreur: valeur différente à l'index " << i << std::endl;
//             return 1;
//         }
//         else
//         {
//             std::cout << "OK index " << i << " -> " << numbers[i] << std::endl;
//         }
//     }

//     std::cout << "\nTest des exceptions:" << std::endl;
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << "Exception (index -2): " << e.what() << std::endl;
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << "Exception (index MAX_VAL): " << e.what() << std::endl;
//     }

//     std::cout << "\nRéaffectation avec de nouvelles valeurs:" << std::endl;
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand() % 100;
//         std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
//     }

//     delete [] mirror;
//     return 0;
// }
