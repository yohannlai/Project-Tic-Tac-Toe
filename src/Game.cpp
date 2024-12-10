#include "../include/Game.hpp"

void draw_game_board(std::array<char, 9> game_board)
{
    for(int i {0}; i < 9; i++)
    {
        int x = i % 3;
        int y = i / 3;
        
        std::cout << "| " << game_board[i] << " ";
        
        if((x-1) == 1)
        {
            std::cout << "|" << '\n';
        }
    }
}
