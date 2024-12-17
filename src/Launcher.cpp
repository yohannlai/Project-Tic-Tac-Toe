#include "../include/Launcher.hpp"
#include "Game.cpp"
#include <ctime> // Pour pouvoir utiliser la fonction time()

// Fonction principale pour démarrer le jeu et choisir le mode de jeu
void boot()
{
    std::srand(std::time(nullptr)); // Initialise le générateur de nombres aléatoires avec l'heure actuelle

    int choice; // Variable pour stocker le choix du mode de jeu
    do{
        // Affiche le menu principal pour choisir le mode de jeu
        std::cout << "Bienvenue dans le jeu du TicTacToe \n" << "Veuillez choisir un mode de jeu : \n" << "1. Deux joueurs \n" << "2. Un joueur contre l'IA \n";
        std::cin >> choice;  // Récupère l'entrée utilisateur

        // Vérifie si l'entrée est invalide ou en dehors des choix proposés
        if(choice != 1 && choice != 2 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Erreur : choisissez un des modes proposés \n" << "\n";
            boot(); // Redémarre la fonction boot() en cas d'erreur
        }
    } while (choice != 1 && choice != 2 || std::cin.fail());

    // Lance le mode de jeu choisi
    switch(choice)
    {
        case 1:
            two_players(); // Lance le mode deux joueurs
            break;
        case 2:
            player_vs_AI(); // Lance le mode contre l'IA
            break;
    }

    play_again(); // Propose de rejouer après la fin de la partie
}

// Fonction pour proposer de rejouer ou quitter le jeu
void play_again()
{
    std::cout << "Désirez-vous rejouer une partie ? \n";

    int replay; // Variable pour stocker le choix de rejouer ou non
    do{
        std::cout << "1. Oui " << "2. Non \n";
        std::cin >> replay;

        // Vérifie si l'entrée est invalide
        if(replay != 1 && replay != 2 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Erreur : choisissez une des options proposées \n" << "\n";
            play_again(); // Redémarre la fonction play_again() en cas d'erreur
        }
    } while (replay != 1 && replay != 2 || std::cin.fail());

    // Gère le choix de l'utilisateur
    switch(replay)
    {
        case 1:
            boot(); // Redémarre le jeu en appelant la fonction boot
            break;
        case 2:
            break; // Quitte la fonction et termine le programme
    }
}
