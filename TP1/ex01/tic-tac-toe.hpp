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
        int lastX;
        int lastY;
    public:
        TicTacToe();
        int jouer(int x, int y);
        Cell gagner(void);
        void printBoard(void);
};

#endif