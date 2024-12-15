#include "../include/Game.hpp"
#include <cstdlib>
#include <ctime>

void draw_game_board(std::array<char, 9> game_board)
{
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

bool check_win(std::array<char, 9> game_board, char symbol)
{
    std::array<std::array<int, 3>, 8> winning_pos {{
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Lignes
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Colonnes
        {0, 4, 8}, {2, 4, 6} // Diagonales
    }};

    for(std::array<int, 3> pos : winning_pos)
    {
        if(game_board[pos[0]] == symbol && game_board[pos[1]] == symbol && game_board[pos[2]] == symbol)
        {
            return true;
        }
    }
    return false;
}

void two_players()
{
    std::cout << "Vous avez choisi le mode \"Deux joueurs\": \n";

    std::array<char, 9> game_board {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    Player player1 = create_player();
    Player player2 = create_player();

    while(player2.symbol == player1.symbol)
    {
        std::cout << player2.name << " doit choisir un symbole différent de " << player1.symbol << " qui est déjà pris par " << player1.name << "\n";
        do{
            std::cout << "Entrez donc l'autre symbole disponible : ";
            std::cin >> player2.symbol;

            if(player2.symbol != 'X' && player2.symbol != 'O' || std::cin.fail())
            {   std::cin.clear();
                std::cin.ignore(255, '\n');
                std::cout << "Ça n'est pas l'autre symbole ! ";
            }
        } while (player2.symbol != 'X' && player2.symbol != 'O' || std::cin.fail());
    }

    bool game_over = false;
    int turn_count {0};
    Player current_player = player1;

    while(!game_over && turn_count < 9)
    {
        draw_game_board(game_board);

        int move;
        do{
            std::cout << current_player.name << " (" << current_player.symbol << "), choisissez une case (1-9): ";
            std::cin >> move;

            if(move < 1 || move > 9 || std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(255, '\n');
                std::cout << "Entrée invalide. On a dit entre 1 et 9 ! \n";
            }
        } while (move < 1 || move > 9);

        if(game_board[move - 1] != 'X' && game_board[move - 1] != 'O')
        {
            game_board[move - 1] = current_player.symbol;
            turn_count++;
        
            if(check_win(game_board, current_player.symbol))
            {
                draw_game_board(game_board);
                std::cout << current_player.name << " a gagné ! \n";
                game_over = true;
            }
            else
            {
                if(current_player.symbol == player1.symbol)
                {
                    current_player = player2;
                }
                else
                {
                    current_player = player1;
                }
            }
        }
        else
        {
            std::cout << "Cette case est déjà occupée. Veuillez réessayer. \n";
        }
    }

    if(!game_over)
    {
        draw_game_board(game_board);
        std::cout << "Match nul ! \n";
    }
}

void player_vs_AI()
{
    std::cout << "Vous avez choisi le mode \"Un joueur contre l'IA\": \n";

    std::array<char, 9> game_board {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    Player player = create_player();
    Player AI;
    AI.name = "IA";

    if(player.symbol == 'X')
    {
        AI.symbol = 'O';
    }
    else
    {
        AI.symbol = 'X';
    }

    bool game_over = false;
    int turn_count {0};
    Player current_player = player;

    while(!game_over && turn_count < 9)
    {
        draw_game_board(game_board);
        int move;

        if(current_player.name == "IA")
        {
            do {
                move = std::rand() % 9;
            } while (game_board[move] == 'X' || game_board[move] == 'O');

            std::cout << "L'IA joue sur la case " << (move + 1) << "\n";

            game_board[move] = AI.symbol;
            turn_count++;
        }
        else
        {
            bool valid_move = false;
            do {
                std::cout << current_player.name << " (" << current_player.symbol << "), choisissez une case (1-9): ";
                std::cin >> move;

                if(move < 1 || move > 9 || std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(255, '\n');
                    std::cout << "Entrée invalide. On a dit entre 1 et 9 ! \n";
                }
                else if(game_board[move - 1] == 'X' || game_board[move - 1] == 'O')
                {
                    std::cout << "Cette case est déjà occupée. Veuillez réessayer. \n";
                }
                else
                {
                    valid_move = true;
                }
            } while (!valid_move);

            game_board[move - 1] = current_player.symbol;
            turn_count++;
        }

        if(check_win(game_board, current_player.symbol))
        {
            draw_game_board(game_board);
            std::cout << current_player.name << " a gagné ! \n";
            game_over = true;
        }
        else
        {
            if(current_player.symbol == player.symbol)
            {
                current_player = AI;
            }
            else
            {
                current_player = player;
            }
        }
    }

    if(!game_over)
    {
        draw_game_board(game_board);
        std::cout << "Match nul ! \n";
    }
}

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