/* Given a 2D m*n matrix of only 0s and 1s, return the number of square
submatrices with only ones.
Approach : For every element, calculate the total number of square submatrices that have only ones with right
bottom corner as that element. 
Whenever i == 0 or j == 0, set it as the element istelf.
Else, if the element is one, then take the minimu of (i-1,j-1),(i-1,j),(i,j-1) and add this value.
Add all such values and return this result.
*/
class Solution
{
public:
    long int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int i, j, n;
        if (m == 0)
            return 0;
        else
            n = matrix[0].size();

        vector<vector<int>> dp(m);
        long int count = 0;
        for (i = 0; i < m; i++)
        {
            dp[i].resize(n);
            for (j = 0; j < n; j++)
            {
                if (matrix[i][j] && i && j)
                    matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i][j - 1], matrix[i - 1][j]});

                count += matrix[i][j];
            }
        }
        return count;
    }
};class Solution {
public:
    
long int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int i,j,n;
        if(m == 0)
            return 0;
        else
            n = matrix[0].size();
        
        vector<vector<int>> dp(m);
        long int count = 0;
        for(i = 0; i < m ;i++)
        {   dp[i].resize(n);
            for(j=0;j<n;j++)
            {    
            if(matrix[i][j] && i && j)
                    matrix[i][j] += min({matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j]});
               
            count += matrix[i][j];
            }
        }
        return count;
    }
};