#include "../include/Player.hpp"

Player create_player(){
    Player player;
    std::cout << "Entrer le nom du joueur: ";
    std::cin >> player.name;

    do{
        std::cout << "Choisissez un symbole (X ou O): ";
        std::cin >> player.symbol;
        
        if(player.symbol != 'X' && player.symbol != 'O' || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Entrée invalide. On a dit X ou O ! ";
        }
    } while (player.symbol != 'X' && player.symbol != 'O' || std::cin.fail());

    return player;
}
