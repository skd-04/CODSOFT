#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

// Function to initialize the board
void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << endl;

        if (i < 2)
            cout << "---|---|---" << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    // Check diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

// Function to check draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }

    return true;
}

int main()
{
    char playAgain;

    do
    {
        initializeBoard();
        currentPlayer = 'X';

        while (true)
        {
            displayBoard();

            int row, col;

            cout << "Player " << currentPlayer << endl;
            cout << "Enter row (1-3): ";
            cin >> row;
            cout << "Enter column (1-3): ";
            cin >> col;

            row--;
            col--;

            if (row < 0 || row > 2 || col < 0 || col > 2)
            {
                cout << "Invalid position! Try again.\n";
                continue;
            }

            if (board[row][col] != ' ')
            {
                cout << "Cell already occupied! Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin())
            {
                displayBoard();
                cout << "Player " << currentPlayer << " Wins!\n";
                break;
            }

            if (checkDraw())
            {
                displayBoard();
                cout << "Game Draw!\n";
                break;
            }

            if (currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thank you for playing!\n";

    return 0;
}