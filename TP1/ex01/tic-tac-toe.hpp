#ifndef TIC_TAC_HPP
#define TIC_TAC_HPP

#include <iostream>

#define WIDTH 3

enum Cell { personne, joueur1, joueur2 };

class TicTacToe
{
    private:
        Cell grid[WIDTH][WIDTH];
        Cell turn;
        Cell winner;
        int rounds;
    public:
        TicTacToe();
        int jouer(int x, int y);
        Cell gagner(int x, int y);
        void printBoard(void);
};

#endif