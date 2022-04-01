#include "tic-tac-toe.hpp"

int main()
{
    TicTacToe board;
    int x,y;
    while(board.gagner() == personne)
    {   
        std::cout << "select a valid ligne :";
        std::cin >> x;
        std::cout << "select a valid column :";
        std::cin >> y;
        board.jouer(x, y);
        board.printBoard();
    }
} 