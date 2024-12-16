#include "../include/Launcher.hpp"
#include "Game.cpp"
#include <ctime>

void boot()
{
    std::srand(std::time(nullptr));

    int choice;
    do{
        std::cout << "Bienvenue dans le jeu du TicTacToe \n" << "Veuillez choisir un mode de jeu : \n" << "1. Deux joueurs \n" << "2. Un joueur contre l'IA \n";
        std::cin >> choice;

        if(choice != 1 && choice != 2 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Erreur : choisissez un des modes proposés \n" << "\n";
            boot();
        }
    } while (choice != 1 && choice != 2 || std::cin.fail());

    switch(choice)
    {
        case 1:
            two_players();
            break;
        case 2:
            player_vs_AI();
            break;
    }

    play_again();
}

void play_again()
{
    std::cout << "Désirez-vous rejouer une partie ? \n";

    int replay;
    do{
        std::cout << "1. Oui " << "2. Non \n";
        std::cin >> replay;

        if(replay != 1 && replay != 2 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Erreur : choisissez une des options proposées \n" << "\n";
            play_again();
        }
    } while (replay != 1 && replay != 2 || std::cin.fail());

    switch(replay)
    {
        case 1:
            boot();
            break;
        case 2:
            break;
    }
}
