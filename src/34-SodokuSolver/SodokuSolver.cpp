#include <vector>
using namespace std;

#define N_1 0x0001
#define N_2 0x0002
#define N_3 0x0004
#define N_4 0x0008
#define N_5 0x0010
#define N_6 0x0020
#define N_7 0x0040
#define N_8 0x0080
#define N_9 0x0100
#define N_ALL 0x01FF

class Solution
{
    vector<vector<int>> myboard;

    void simplify_row(vector<vector<char>> &board, int row_num)
    {
        int x;
        for (x = 0; x < 9; x++)
        {
        }
    }
    void simplify_col(vector<vector<char>> &board, int col_num)
    {
        int y;
        for (y = 0; y < 9; y++)
        {
        }
    }
    void simplify_sub(vector<vector<char>> &board)
    {
        int x;
        for (x = 0; x < 9; x++)
        {
        }
    }
    void init_board(vector<vector<char>> &board)
    {
        int x, y;
        for (x = 0; x < 9; x++)
        {
            for (y = 0; y < 9; y++)
            {
                switch (board[x][y])
                {
                case '1':
                    myboard[x][y] = N_1;
                    break;
                case '2':
                    myboard[x][y] = N_2;
                    break;
                case '3':
                    myboard[x][y] = N_3;
                    break;
                case '4':
                    myboard[x][y] = N_4;
                    break;
                case '5':
                    myboard[x][y] = N_5;
                    break;
                case '6':
                    myboard[x][y] = N_6;
                    break;
                case '7':
                    myboard[x][y] = N_7;
                    break;
                case '8':
                    myboard[x][y] = N_8;
                    break;
                case '9':
                    myboard[x][y] = N_9;
                    break;
                case '.':
                    myboard[x][y] = N_ALL;
                    break;
                }
            }
        }
    }
    void copy_myboard(vector<vector<char>> &board)
    {
        int x, y;
        for (x = 0; x < 9; x++)
        {
            for (y = 0; y < 9; y++)
            {

                switch (myboard[x][y])
                {
                case N_1:
                    board[x][y] = '1';
                    break;
                case N_2:
                    board[x][y] = '2';
                    break;
                case N_3:
                    board[x][y] = '3';
                    break;
                case N_4:
                    board[x][y] = '4';
                    break;
                case N_5:
                    board[x][y] = '5';
                    break;
                case N_6:
                    board[x][y] = '6';
                    break;
                case N_7:
                    board[x][y] = '7';
                    break;
                case N_8:
                    board[x][y] = '8';
                    break;
                case N_9:
                    board[x][y] = '9';
                    break;
                default:
                    board[x][y] = '.';
                    break;
                }
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        init_board(board);
    }
};