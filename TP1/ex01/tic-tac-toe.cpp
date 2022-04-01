#include "tic-tac-toe.hpp"

TicTacToe::TicTacToe()
{
    for(int i = 0; i < WIDTH ; i++)
    {
        for(int j = 0; j < WIDTH ; j++)
            this->grid[i][j] = personne;
    }
    this->turn = joueur1;
    this->winner = personne;
    this->lastX = 0;
    this->lastY = 0;
}

int TicTacToe::jouer(int x, int y)
{
    x--;
    y--;
    if(winner != personne)
        return 1;
    if(x < 0 || x > WIDTH || y < 0 || y > WIDTH)
    {
        std::cerr << "this cell is out of range" << std::endl;
        return 1;
    }
    if(grid[x][y] != personne)
    {
        std::cerr << "this cell is already full" << std::endl;
        return 1;
    }
    grid[x][y] = turn;
    lastX = x;
    lastY = y;
    winner = gagner();
    if(winner != personne)
        std::cout << "* the player" << winner << " has won *" << std::endl;    
    if(turn == joueur1)
        turn = joueur2;
    else
        turn = joueur1;
    return 0;
}

Cell TicTacToe::gagner(void)
{
    if(winner != personne)
        return winner;
    if(grid[lastX][0] == turn && grid[lastX][1] == turn && grid[lastX][2] == turn )
        return turn;
    if(grid[0][lastY] == turn && grid[1][lastY] == turn && grid[2][lastY] == turn)
        return turn;
    if ((grid[0][0] == turn && grid[1][1] == turn && grid[2][2] == turn) ||
        (grid[0][2] == turn && grid[1][1] == turn && grid[2][0] == turn))
        return turn;
    return personne;  
}

void TicTacToe::printBoard(void)
{
    for(int i = 0; i < WIDTH ; i++)
    {
        for(int j = 0; j < WIDTH ; j++)
        {
            if(this->grid[i][j] == joueur1)
                std::cout << "X";
            else if(this->grid[i][j] == joueur2)
                std::cout << "O";
            else
                std::cout << "-";
        }
        std::cout << std::endl;
    }
}