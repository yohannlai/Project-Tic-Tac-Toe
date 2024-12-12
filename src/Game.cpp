#include "../include/Game.hpp"

void draw_game_board()
{
    std::array<char, 9> game_board {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(int i {0}; i < 9; i++)
    {
        int x = i % 3;
        
        std::cout << "| " << game_board[i] << " ";
        
        if((x-1) == 1)
        {
            std::cout << "|" << '\n';
        }
    }
}

void two_players()
{
    Player player1 = create_player();
    Player player2 = create_player();
}

void player_vs_AI()
{
    Player player = create_player();
}

void boot()
{
    std::cout << "Bienvenue dans le jeu du TicTacToe \n" << "Veuillez choisir un mode de jeu : \n" << "1. Deux joueurs \n" << "2. Un joueur contre l'IA \n";
    int choice;
    std::cin >> choice;
    switch(choice)
    {
        case 1:
            std::cout << "Vous avez choisi le mode \"Deux joueurs\": \n";
            two_players();
            draw_game_board();
            break;
        case 2:
            std::cout << "Vous avez choisi le mode \"Un joueur contre l'IA\": \n";
            player_vs_AI();
            draw_game_board();
            break;
        default:
            std::cout << "Erreur : choisissez un des modes proposés \n" << "\n";
            boot();
            break;
    }
}