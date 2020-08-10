/*
 Word search 1 with a dictionary of words 
*/
class Solution {
public:
    int num;
    vector<string> dict;
    bool inRange(int i, int j, int m, int n, vector<vector<bool>>& visited)
    {
        return (i >=0 && j >= 0 && i<m && j<n && !visited[i][j]);
    }
    map<string,bool> found;
    bool check(vector<string> dict, string word)
    {
    for(int i = 0;i<num;i++)
        {  if(dict[i] == word && !found[word])
            {  found[word]
                return true;
                }
        }
        return false;
    }
    
    void findWords(vector<string>& res,vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& start)
    {
        
        int m,n;
        m = board.size();
        n = board[0].size();
        start = start + board[i][j];
        if(check(dict, start))
            res.push_back(start);
        visited[i][j] = true;
        if( inRange(i+1,j,m,n,visited) )
            findWords(res,board,visited,i+1,j,start);
        if( inRange(i,j-1,m,n,visited) )
            findWords(res,board,visited,i,j-1,start);
        if( inRange(i-1,j,m,n,visited) )
            findWords(res,board,visited,i-1,j,start);
        if( inRange(i,j+1,m,n,visited) )
            findWords(res,board,visited,i,j+1,start);
        start.erase(start.size()-1);
        visited[i][j] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        num = words.size();
        int i,j,m,n;
        m = board.size();
        n = board[0].size();
        dict = words;
        string start = "";
        vector<string> res;
        vector<vector<bool>> visited;
        visited.resize(m);
        for(i=0;i<m;i++)
        { 
            visited[i].resize(n);
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
            findWords(res,board,visited,i,j,start);      
            }
        }
        return res;
        
    }
};