/*
 Given a board (2D array) of characters - return true if a given word can be traced 
 by moving through the matrix (only adjacent moves are allowed - Up, Down, Left and Right)
 Approach - simple backtracking solution - for every index, start at that index and check
 if that position contains the corresponding character and check all neighbours (if any of them 
 return TRUE), then return TRUE
 Hold a visited array (LC question) - if indices cannot be repeated
 No need of one (IB)
*/
bool inRange(int i, int j, int m, int n, vector<vector<bool>> visited)
        
    {
        return (i>=0 && i<m && j>=0 && j<n );
    }
    
    bool findlol(vector<string>& board,int i, int j, string word, vector<vector<bool>>& visited)
    { 
        
        if(word.size() == 1)
        {
            
            return word[0] == board[i][j];
            
        }
        int m = board.size();
        int n = board[0].size();
        visited[i][j] = true;
        if(inRange(i-1,j,m,n, visited) && word[0] == board[i][j] && findlol(board,i-1,j,word.substr(1), visited))
           
            return true;
        
        
        if(inRange(i,j-1,m,n, visited) && word[0] == board[i][j] && findlol(board,i,j-1,word.substr(1), visited))
            return true;
        
        if(inRange(i+1,j,m,n, visited) && word[0] == board[i][j] && findlol(board,i+1,j,word.substr(1), visited))
            return true;
        
        if(inRange(i,j+1,m,n, visited) && word[0] == board[i][j] && findlol(board,i,j+1,word.substr(1), visited))
            return true;
        visited[i][j] = false;   
        return false;
    }
int Solution::exist(vector<string> &board, string word) {
    int i,j,m,n;
    vector<vector<bool>> visited;
        m = board.size();
        n = board[0].size();
        visited.resize(m);
        for(i=0;i<m;i++)
        {
            visited[i].resize(n);
        }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {  
                if(findlol(board,i,j,word, visited))
                    return 1;
            }
        }
        return 0;
    }

