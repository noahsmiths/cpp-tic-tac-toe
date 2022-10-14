#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TicTacToe
{
private:
    string turn;
    int playerXScore;
    int playerOScore;
    int moves;
    string board[3][3];
    void switchTurn();
    bool move(int);
    int checkForWin();

public:
    TicTacToe();
    void start();
    string getTurn();
    string stringifyBoard();
};

TicTacToe::TicTacToe()
{
    turn = "O";
    playerXScore = 0;
    playerOScore = 0;
    moves = 0;

    // Initialize the board
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            board[i][j] = to_string((i * 3) + j + 1);
        }
    }
}

void TicTacToe::start()
{
    while (checkForWin() == 0) {
        cout << stringifyBoard() << "\n";

        int spot;
        cout << "Player " << turn << ", enter the number of the spot you want: ";
        cin >> spot;

        if (!move(spot)) {
            cout << "Illegal move. Try again.\n";
        } else {
            if (checkForWin() == 1) {
                cout << stringifyBoard() << "\n";
                cout << "Player " << turn << " Won! Congratulations!" << endl;
                return;
            } else {
                switchTurn();
            }
        }
    }

    cout << "Cats got it - Better luck next time!" << endl;
}

void TicTacToe::switchTurn()
{
    turn = (turn == "X") ? "O" : "X";
}

bool TicTacToe::move(int location)
{
    int row = (location - 1) / 3;
    int col = (location - 1) % 3;

    if (board[row][col] != "X" && board[row][col] != "O") {
        board[row][col] = turn;
        moves++;
        return true;
    } else {
        return false;
    }
}

int TicTacToe::checkForWin()
{
    for (int i = 0; i <= 2; i++) { // Check for horizontal or vertical win
        bool horizontalWin = true;
        bool verticalWin = true;
        bool topLeftToBottomRight = true;
        bool topRightToBottomLeft = true;

        for (int j = 0; j <= 1; j++) {
            if (board[i][j] != board[i][j + 1]) {
                horizontalWin = false;
            }

            if (board[j][i] != board[j + 1][i]) {
                verticalWin = false;
            }

            if (board[j][j] != board[j + 1][j + 1]) {
                topLeftToBottomRight = false;
            }

            if (board[2 - j][2 - j] != board[2 - j - 1][2 - j - 1]) {
                topRightToBottomLeft = false;
            }
        }

        if (horizontalWin || verticalWin || topLeftToBottomRight || topRightToBottomLeft) return 1;
    }

    if (moves >= 9) return 2;

    return 0;
}

string TicTacToe::getTurn()
{
    return turn;
}

string TicTacToe::stringifyBoard()
{
    string stringBoard = "-------------\n";

    for (int i = 0; i <= 2; i++) {
        stringBoard += "|";

        for (int j = 0; j <= 2; j++) {
            stringBoard += " " + board[i][j] + " |";
        }

        stringBoard += "\n";
    }

    stringBoard += "-------------";
    return stringBoard;
}

int main()
{
    cout << "Welcome to Tic Tac Toe! Ready to play? (Y/n) ";
    string readyOrNot;
    getline(cin, readyOrNot);

    if (readyOrNot != "y" && readyOrNot != "Y") {
        cout << "Ok, goodbye.";
        return 0;
    }

    TicTacToe board;
    board.start();
    cin.ignore();
    cin.get();
    return 0;
}