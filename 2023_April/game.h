// 2023/04/21 12:58:49
#include <iostream>
#include <vector>

void menu();

void game();

void displayBoard(const std::vector<std::vector<int>>& board, const std::vector<std::vector<int>>& count_board);

void initBoard(std::vector<std::vector<int>>& true_board, std::vector<std::vector<int>>& count_board);

bool location(std::vector<std::vector<int>>& display_board, const std::vector<std::vector<int>>& true_board, const std::vector<std::vector<int>>& count_board);

bool check();