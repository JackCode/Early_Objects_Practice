#include <iostream>
using namespace std;

void display_board(char current[][3]);
void update_board(char current[][3], char player, int row, int col);
bool check_winner(char current[][3]);

int main() {

    int row, col, turnNum = 1;
    bool xTurn = true,      // X always starts
         winner = false;
    char mark;

    char board[3][3] { {'*', '*', '*'},
                       {'*', '*', '*'},
                       {'*', '*', '*'} };

    display_board(board);

    while ( !winner && turnNum != 10)
    {
        mark = xTurn ? 'X' : 'O';
        do
        {
            cout << "\n";
            cout << mark << ", enter move (row) (col): ";
            cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != '*')
                cout << "Error. Invalid location.\n";

        } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != '*');

        update_board(board, mark, row, col);
        display_board(board);
        winner = check_winner(board);
        if (!winner) turnNum++;
        xTurn = !xTurn;
    }

    display_board(board);

    if (turnNum == 10)
        cout << "\n\nTIE GAME!\n\n";
    else
        cout << "\n\n" << mark << " WINS!\n\n";
    
    return 0;
}

void display_board(char current[][3])
{
    system("clear");
    cout << "   1   2   3" << endl
         << "1  " << current[0][0] << " | " << current[0][1] << " | " << current[0][2] << endl
         << "  -----------" << endl
         << "2  " << current[1][0] << " | " << current[1][1] << " | " << current[1][2] << endl
         << "  -----------" << endl
         << "3  " << current[2][0] << " | " << current[2][1] << " | " << current[2][2] << endl;
}

void update_board(char current[][3], char player, int row, int col)
{
    current[row-1][col-1] = player;
}

bool check_winner(char board[][3])
{
    string lines[8];
    
    // Horizontal Lines
    lines[0] += board[0][0]; // Row 1
    lines[0] += board[0][1];
    lines[0] += board[0][2];
    lines[1] += board[2][0]; // Row 2
    lines[1] += board[2][1];
    lines[1] += board[2][2];
    lines[2] += board[3][0]; // Row 3
    lines[2] += board[3][1];
    lines[2] += board[3][2];

    // Vertical Lines
    lines[3] += board[0][0]; // Col 1
    lines[3] += board[1][0];
    lines[3] += board[2][0];
    lines[4] += board[0][1]; // Col 2
    lines[4] += board[1][1];
    lines[4] += board[2][1];
    lines[5] += board[0][2]; // Col 3
    lines[5] += board[1][2]; 
    lines[5] += board[2][2];

    // Diagonal Lines
    lines[6] += board[0][0]; // TL->BR
    lines[6] += board[1][1];
    lines[6] += board[2][2];
    lines[7] += board[2][0]; // BL->TR
    lines[7] += board[1][1];
    lines[7] += board[0][2];

    for ( int i = 0; i < 8; i++ )
    {
        if (lines[i] == "XXX" || lines[i] == "OOO")
            return true;
    }

    return false;
}