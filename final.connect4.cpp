#include<iostream>
#include <string>
using namespace std;
// Connect 4 Game
// Created By: Devin Stewart
// 05/7/2023


// Define a struct to hold player information
struct playerInfo {

	string p1;
	string p2;
	char p1Symbol;
	char p2Symbol;

};

// Define the game board as a 2D array of integers
int board[7][6] = { {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0} };


void displayBoard(char p1Symbol, char p2Symbol)
{
    cout << "-------------------------------" << endl;
    for (int row = 5; row >= 0; row--) {
        cout << "|";// Start each row with a vertical bar
        // Loop over each column of the board
        for (int col = 0; col < 7; col++) {
            // If the cell is empty, print spaces
            if (board[col][row] == 0) {
                cout << "   " << "|";
            }
            // If the cell contains Player 1's symbol, print the symbol
            else if (board[col][row] == 1) {
                cout << " " << p1Symbol << " " << "|";
            }
            // If the cell contains Player 2's symbol, print the symbol
            else if (board[col][row] == 2) {
                cout << " " << p2Symbol << " " << "|";
            }
        }
        cout << endl << "-------------------------------" << endl;
    }
    cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |" << endl;
    cout << "-------------------------------" << endl;
}




void getPLayerInfo(playerInfo& info) {

    cout << "Enter Player 1 name: ";
    cin >> info.p1;

    cout << "Enter Player 2 name: ";
    cin >> info.p2;

    cout << info.p1 << " choose a symbol: " <<endl;
    cin >> info.p1Symbol;

    cout << info.p2 << " choose a symbol: " <<endl;
    cin >> info.p2Symbol;

}

void makeMove(int player, int col) {
    // Loop through all rows in the specified column
    for (int row = 0; row < 6; row++) {
        // If the current cell in the column is empty (0), then the player can make their move here
        if (board[col][row] == 0) {
            // Set the cell to the player's number
            board[col][row] = player;
            // Exit the loop since the move has been made
            break;
        }
    }
}

bool checkWin(int player) {
    int count = 0;

    // Check horizontally
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 4; col++) {
            count = 0;
            for (int i = 0; i < 4; i++) {
                if (board[col + i][row] == player) {
                    count++;
                }
            }
            if (count == 4) {
                return true;
            }
        }
    }

    // Check vertically
    for (int col = 0; col < 7; col++) {
        for (int row = 0; row < 3; row++) {
            count = 0;
            for (int i = 0; i < 4; i++) {
                if (board[col][row + i] == player) {
                    count++;
                }
            }
            if (count == 4) {
                return true;
            }
        }
    }

    // Check diagonally (positive slope)
    for (int col = 0; col < 4; col++) {
        for (int row = 0; row < 3; row++) {
            count = 0;
            for (int i = 0; i < 4; i++) {
                if (board[col + i][row + i] == player) {
                    count++;
                }
            }
            if (count == 4) {
                return true;
            }
        }
    }

    // Check diagonally (negative slope)
    for (int col = 0; col < 4; col++) {
        for (int row = 3; row < 6; row++) {
            count = 0;
            for (int i = 0; i < 4; i++) {
                if (board[col + i][row - i] == player) {
                    count++;
                }
            }
            if (count == 4) {
                return true;
            }
        }
    }

    // If we reach this point, the player has not won
    return false;
}

bool checkDraw() {
    // Check if the board is full
    for (int col = 0; col < 7; col++) {
        if (board[col][5] == 0) {
            return false;
        }
    }

    // If we reach this point, the board is full and the game is a draw
    return true;
}


void playerMoves(playerInfo& info){
    int currentPlayer = 1;
    int col;

    while (true) {
        //print the board
        displayBoard(info.p1Symbol, info.p2Symbol);


        // Prompt the current player to make a move
        cout << "Player " << currentPlayer << ", enter a column number: ";

        cin >> col;
        if (col < 1 || col > 7) {
            cout << "Invalid choice, go again " << currentPlayer << endl;
            continue;
        }

        // Make the move
        makeMove(currentPlayer, col - 1);


        // Check for a win
        if (checkWin(currentPlayer)) {
            displayBoard(info.p1Symbol, info.p2Symbol);
            if (currentPlayer == 1) {
                cout << info.p1 << " Wins!!! " << endl;
                break;
            }
            else {
                cout << info.p2 << " Wins!!!";
            }
        }

        // Check for a draw
        if (checkDraw()) {
            displayBoard(info.p1Symbol, info.p2Symbol);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;




    }
}

void resetBoard() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            board[i][j] = 0;
        }
    }
}




int main()
{
    playerInfo info;
    bool gameOver = false;
    char start;

    // game loop
    while (!gameOver) {
        cout << "Do you want to start a new game?:(Y/N)";
        cin >> start;

        if (start == 'Y') {
            // Get player information
            getPLayerInfo(info);

            // Reset the board
            resetBoard();

            // Start the game
            playerMoves(info);
        }

        else if (start == 'N') {
            gameOver = true;
            cout << "Game terminated";

        

        }
    }

    
	
}




