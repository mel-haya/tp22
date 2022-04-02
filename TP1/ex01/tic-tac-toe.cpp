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
    rounds = 0;
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
    rounds++;
    winner = gagner(x, y);
    if(winner != personne)
        std::cout << "* the player" << winner << " has won *" << std::endl;
    else if(rounds == 9)
        std::cout << "* DRAW *" << std::endl;
    if(turn == joueur1)
        turn = joueur2;
    else
        turn = joueur1;
    return 0;
}

Cell TicTacToe::gagner(int x, int y)
{
    if(winner != personne)
        return winner;
    if(grid[x][0] == turn && grid[x][1] == turn && grid[x][2] == turn )
        return turn;
    if(grid[0][y] == turn && grid[1][y] == turn && grid[2][y] == turn)
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
    if(rounds == 9)
        exit(0);
}