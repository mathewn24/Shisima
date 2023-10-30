//
// Name:       MATHEWS, Noel
// Student ID: 1155130840
// Email:      1155130840@link.cuhk.edu.hk
//

#include "shisimaboard.h"
#include <iostream>

int power(int base, int exponent){

    int result = 1;
    int i;
    for (i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;

}

int absolute(int x){

    if (x < 0)
    {
        x *= (-1);
    }
    return x;
}

/* Returns the state of position pos of the game board. */
int boardState(int board, int pos) {

    int p, player;

    p = power(10,9-pos);
    player = (board / p) % 10;
    
    if (player == 1)
    {
        return 1;
    } else if (player == 2)
    {
        return 2;
    } else
    {
        return 0;
    }    

}

/* Prints the board to the screen. DO NOT MODIFY! */
void printBoard(int board) {
    std::cout << "  " << boardState(board, 1) << "-" << boardState(board, 2) << "-" << boardState(board, 3) << std::endl;
    std::cout << " / \\|/ \\" << std::endl;
    std::cout << boardState(board, 4) << "---" << boardState(board, 5) << "---" << boardState(board, 6) << std::endl;
    std::cout << " \\ /|\\ /" << std::endl;
    std::cout << "  " << boardState(board, 7) << "-" << boardState(board, 8) << "-" << boardState(board, 9) << std::endl;
}

/* Performs the task of player p moving a piece from position pos1 to position
   pos2 of board. */
bool movePiece(int &board, int pos1, int pos2, int p) {

    // Find row and column of pos1 and pos2 to check adjacency.
    int r1, r2, c1, c2;
    r1 = (pos1-1) / 3;
    c1 = (pos1-1) % 3;
    r2 = (pos2-1) / 3;
    c2 = (pos2-1) % 3;

    bool adjacency;

    if ((pos1 == 5) || (pos2 == 5) || (1 == (absolute(c1-c2) + absolute(r1-r2))))
    {
        adjacency = true;
    } else
    {
        adjacency = false;
    }

    // Condition to validate player move.
    if ((pos1 > 9) || (pos2 > 9) ||  // If position is out of bounds.
        (pos1 < 1) || (pos2 < 1) || 
        (p != boardState(board, pos1)) || // If start position is not the current player's piece.
        (0 != boardState(board, pos2)) || // If end position is not empty (0).
        adjacency == false)
    {
        return false;
    }

    board = (board - p*(power(10, (9-pos1)))) + p*(power(10, (9-pos2)));
    return true;
}

/* Checks if any player has formed a line of three pieces crossing the middle
   of the board. */
int formLine(int board) {
    int winner;
    if (
        (boardState(board, 1) == boardState(board, 5)) && (boardState(board, 5) == boardState(board, 9)) ||
        (boardState(board, 2) == boardState(board, 5)) && (boardState(board, 5) == boardState(board, 8)) ||
        (boardState(board, 3) == boardState(board, 5)) && (boardState(board, 5) == boardState(board, 7)) ||
        (boardState(board, 4) == boardState(board, 5)) && (boardState(board, 5) == boardState(board, 6)))
        {

        if (boardState(board, 5) == 1)
        {
            return 1;
        } else if (boardState(board, 5) == 2)
        {
            return 2;
        }
        
    }

    return 0;
}