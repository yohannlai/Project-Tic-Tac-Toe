#pragma once
#include<iostream>
#include<array>

void draw_game_board(std::array<char, 9> game_board);

bool check_win(std::array<char, 9> game_board, char symbol);

void two_players();

void player_vs_AI();

void boot();

void play_again();