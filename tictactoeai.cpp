#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Game board setup
vector<string> board = { "-", "-", "-", "-", "-", "-", "-", "-", "-" };

// Print the game board
void printBoard() {
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Check if the game is over
string checkGameOver() {
    vector<vector<int>> winPatterns = {
        {0,1,2},{3,4,5},{6,7,8}, // Rows
        {0,3,6},{1,4,7},{2,5,8}, // Columns
        {0,4,8},{2,4,6}          // Diagonals
    };

    for (auto pattern : winPatterns) {
        string a = board[pattern[0]], b = board[pattern[1]], c = board[pattern[2]];
        if (a == b && b == c && a != "-") {
            return a; // Winner ("X" or "O")
        }
    }
    if (count(board.begin(), board.end(), "-") == 0) {
        return "tie";
    }
    return "play"; // Game continues
}

// Minimax Algorithm
int minimax(bool isMaximizing) {
    string result = checkGameOver();
    if (result == "O") return 10;
    if (result == "X") return -10;
    if (result == "tie") return 0;

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] == "-") {
                board[i] = "O";
                int score = minimax(false);
                board[i] = "-";
                bestScore = max(score, bestScore);
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] == "-") {
                board[i] = "X";
                int score = minimax(true);
                board[i] = "-";
                bestScore = min(score, bestScore);
            }
        }
        return bestScore;
    }
}

// AI's turn using Minimax
void aiTurn() {
    int bestScore = -1000;
    int bestMove = -1;
    for (int i = 0; i < 9; i++) {
        if (board[i] == "-") {
            board[i] = "O";
            int score = minimax(false);
            board[i] = "-";
            if (score > bestScore) {
                bestScore = score; 
                bestMove = i;
            }
        }
    }
    board[bestMove] = "O";
    cout << "AI (O) chose position " << (bestMove + 1) << endl;
    printBoard();
}

// Human player's turn
void takeTurn(string player) {
    cout << player << "'s turn." << endl;
    cout << "Choose a position from 1-9: ";
    int position;
    cin >> position;
    position -= 1;
    while (position < 0 || position > 8 || board[position] != "-") {
        cout << "Invalid input or position already taken. Choose a different position: ";
        cin >> position;
        position -= 1;
    }
    board[position] = player;
    printBoard();
}

// Main game loop
int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "You are 'X', AI is 'O'" << endl;
    printBoard();

    string currentPlayer = "X";
    bool gameOver = false;

   while (!gameOver) {
    if (currentPlayer == "X") {
        takeTurn("X");
    } else {
        aiTurn();
    }

    string result = checkGameOver();
    if (result == "X") {
        cout << "Player X wins!" << endl;
        gameOver = true;
    } else if (result == "O") {
        cout << "AI wins!" << endl;
        gameOver = true;
    } else if (result == "tie") {
        cout << "It's a tie!" << endl;
        gameOver = true;
    } else {
        // Simplified version of: currentPlayer = (currentPlayer == "X") ? "O" : "X";
        if (currentPlayer == "X") {
            currentPlayer = "O";
        } else {
            currentPlayer = "X";
        }
    }
}


    return 0;
}
