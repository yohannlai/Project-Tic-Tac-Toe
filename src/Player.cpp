#include<iostream>
#include "../include/Player.hpp"

Player create_player(){
    Player player;
    std::cout << "Enter player name: ";
    std::cin >> player.name;

    do{
        std::cout << "Choose a symbol (X or O): ";
        std::cin >> player.symbol;
    } while (player.symbol != 'X' && player.symbol != 'O');

    return player;
}
