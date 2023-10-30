//
// Name:       MATHEWS, Noel
// Student ID: 1155130840
// Email:      1155130840@link.cuhk.edu.hk
//

#include "shisimaboard.h"
#include <iostream>

int main(){
    bool gameOver = false;
    int gameBoard = 102102102;
    int currentPlayer = 1;
    int from, to;
    bool validMove = false;
    int winner;

    printBoard(gameBoard);
    
    while (gameOver == false)
    {
        if (formLine(gameBoard))
        {
            winner = formLine(gameBoard);
            std::cout << "Player " << winner << " wins!" << std::endl;
            gameOver = true;
        } else
        {
            while (true)
            {
                std::cout << "Player " << currentPlayer << " (from to):";
                std::cin >> from >> to;                
                validMove = movePiece(gameBoard, from, to, currentPlayer);
                if (validMove)
                {
                    break;
                } else{
                    std::cout << "Invalid. Try again!" << std::endl;
                }
            }
            
            printBoard(gameBoard);
            if (currentPlayer == 1)
            {
                currentPlayer = 2;
            } else
            {
                currentPlayer = 1;
            }
        }

    }

    return 0;
}