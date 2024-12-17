#include "Player.cpp"
#include "../include/Game.hpp"
#include <cstdlib> // Pour pouvoir utiliser la fonction rand()

// Affiche le plateau de jeu
void draw_game_board(std::array<char, 9> game_board)
{
    for(int i {0}; i < 9; i++)
    {
        int x = i % 3;
        
        std::cout << "| " << game_board[i] << " ";
        
        // Ajoute un séparateur après chaque troisième case
        if((x-1) == 1)
        {
            std::cout << "|" << '\n';
        }
    }
}

// Vérifie si un joueur a gagné à partir d'un tableau avec les positions gagnantes
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

// Mode 2 joueurs
void two_players()
{
    std::cout << "Vous avez choisi le mode \"Deux joueurs\": \n";

    std::array<char, 9> game_board {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    Player player1 = create_player();
    Player player2 = create_player();

    // Assure que les deux joueurs ont des symboles différents
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

    // Boucle de jeu
    while(!game_over && turn_count < 9)
    {
        draw_game_board(game_board);

        int move;
        do{
            std::cout << current_player.name << " (" << current_player.symbol << "), choisissez une case (1-9): ";
            std::cin >> move;

            // Vérification de la validité de l'entrée
            if(move < 1 || move > 9 || std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(255, '\n');
                std::cout << "Entrée invalide. On a dit entre 1 et 9 ! \n";
            }
        } while (move < 1 || move > 9);

        // Si la case est libre, on effectue le coup
        if(game_board[move - 1] != 'X' && game_board[move - 1] != 'O')
        {
            game_board[move - 1] = current_player.symbol;
            turn_count++;
        
            // Vérification si un joueur a gagné
            if(check_win(game_board, current_player.symbol))
            {
                draw_game_board(game_board);
                std::cout << current_player.name << " a gagné ! \n";
                game_over = true;
            }
            else
            {
                // Changement de joueur
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

    // Si aucune victoire, match nul
    if(!game_over)
    {
        draw_game_board(game_board);
        std::cout << "Match nul ! \n";
    }
}

// Mode 1 joueur contre l'IA
void player_vs_AI()
{
    std::cout << "Vous avez choisi le mode \"Un joueur contre l'IA\": \n";

    std::array<char, 9> game_board {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    Player player = create_player();
    Player AI;
    AI.name = "IA";

    // L'IA choisit un symbole opposé à celui du joueur
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

    // Boucle de jeu pour le mode 1 joueur contre IA
    while(!game_over && turn_count < 9)
    {
        draw_game_board(game_board);
        int move;
        
        // L'IA joue de manière aléatoire
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

                // Vérification de la validité de l'entrée
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

        // Vérification si un joueur a gagné
        if(check_win(game_board, current_player.symbol))
        {
            draw_game_board(game_board);
            std::cout << current_player.name << " a gagné ! \n";
            game_over = true;
        }
        else
        {
            // Changement de joueur
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

    // Si aucune victoire, match nul
    if(!game_over)
    {
        draw_game_board(game_board);
        std::cout << "Match nul ! \n";
    }
}
