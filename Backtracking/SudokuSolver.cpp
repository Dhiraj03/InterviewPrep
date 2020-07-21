/* Solve the Sudoku Board
Approach : for every empty position in the board, try all 9 diff digits,
and for every digit that results in a valid board (partially filled), 
recursively call the function for the next empty position - increment
column by 1, if column is last one, then go to the next row, if its last row and
last column, return TRUE
*/
int N = 9;
char unassigned = '.';

bool check(vector<vector<char>> &board, int i, int j, char val)
{
    int row = i - i % 3, column = j - j % 3;
    for (int x = 0; x < 9; x++)
        if (board[x][j] == val)
            return false;
    for (int y = 0; y < 9; y++)
        if (board[i][y] == val)
            return false;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            if (board[row + x][column + y] == val)
                return false;
    return true;
}

bool solve(vector<vector<char>> &board, int row, int col)
{
    if (row == N - 1 && col == N)
    {
        return true;
    }

    if (col == N)
    {
        col = 0;
        row = row + 1;
    }
    if (board[row][col] != unassigned)
        return solve(board, row, col + 1);
    for (char i = '1'; i <= '9'; i++)
    {
        if (check(board, row, col, i))
        {
            board[row][col] = i;
            if (solve(board, row, col + 1))
                return true;
            board[row][col] = '.';
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char>> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    bool res = solve(A, 0, 0);

    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
