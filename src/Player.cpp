#include<iostream>
#include "../include/Player.hpp"

Player create_player(){
    Player player;
    std::cout << "Entrer le nom du joueur: ";
    std::cin >> player.name;

    do{
        std::cout << "Choisissez un symbole (X ou O): ";
        std::cin >> player.symbol;
    } while (player.symbol != 'X' && player.symbol != 'O');

    return player;
}
