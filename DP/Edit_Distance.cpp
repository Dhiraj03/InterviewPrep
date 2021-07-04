/* Given two strings A and B, return the number of ops
to be done to make them identical (addition/deletion/replacement)
dp[i][j] => Number of ops required to make A[0..i] and B[0..j] equal
if the two characters are equal, then dp[i][j] will remain the same as 
previous characters i.e dp[i-1][j-1], else, we will take the minimum of dp[i-1][j],
dp[j-1][i] and dp[i-1][j-1] and add one (since one operation is to be done).
return dp[m][n], where m = size of A, n  = size of B
*/

int min(int a, int b)
{
    return a < b ? a : b;
}

int Solution::minDistance(string A, string B)
{
    int m = A.size();
    int n = B.size();
    int i, j;
    vector<vector<int>> dp(m + 1);
    for (i = 0; i <= m; i++)
    {
        dp[i].resize(n + 1);
    }

    int replacements = 0;
    for (i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (i = 0; i <= n; i++)
    {
        dp[0][i] = i;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        }
    }
    return dp[m][n];
}
