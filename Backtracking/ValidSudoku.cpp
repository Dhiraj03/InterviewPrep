/*
  Given a 9*9 grid, return true if it is a valid ( not necessarily)
  sudoku board.
*/ 
    bool check(vector<string> &board, int i, int j, char val)
{
    char temp = board[i][j];
        board[i][j] = '.';
    int row = i - i%3, column = j - j%3;
    for(int x=0; x<9; x++) if(board[x][j] == val) return false;
    for(int y=0; y<9; y++) if(board[i][y] == val) return false;
    for(int x=0; x<3; x++)
    for(int y=0; y<3; y++)
        if(board[row+x][column+y] == val) return false;
    board[i][j] = temp;
    return true;
}
    
    bool solve(vector<string> board, int row, int col, int N, char unassigned)
    {   
        if(row == N-1 && col == N)
        {
        return true;
        }
        
        if(col == N)
        {
            col = 0;
            row = row + 1;
        }
        if(board[row][col] == unassigned)
            return solve(board, row, col+1, N, unassigned);
        if(check(board,row,col,board[row][col]))
            return solve(board, row, col+1, N, unassigned);
    return false;
    }
    
    

int Solution::isValidSudoku(const vector<string> &A) {
    int N = 9;
    char unassigned = '.';
    return solve(A,0,0,N,unassigned) ? 1 : 0;
}
