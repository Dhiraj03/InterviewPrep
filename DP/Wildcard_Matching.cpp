/* Given two strings, one text and the other pattern, return whether the pattern 
matches the string( ? -> exactly one character, * -> zero or more characters)
Approach - bottom-up approach, where we maintain a matrix where dp[i][j] is true
if text[0...i] can be represented by pat[0...j], 
if text[i-1] == pat[j-1] or if pat[j-1] is ?, then dp[i][j] = dp[i-1][j-1]
else if pat[j-1] is *, then dp[i][j] = dp[i-1][j] || dp[i][j-1]

** TLE on LC, passed on IB
*/
int Solution::isMatch(const string s, const string p)
{
    int m = s.size();
    int n = p.size();
    int i, j;
    vector<vector<bool>> dp(m + 1);
    for (i = 0; i <= m; i++)
    {
        dp[i].resize(n + 1);
    }
    for (i = 1; i <= m; i++)
    {
        dp[i][0] = false;
    }
    bool flag = true;
    for (i = 1; i <= n; i++)
    {
        if (flag && p[i - 1] == '*')
            dp[0][i] = true;
        else
        {
            flag = false;
            dp[0][i] = false;
        }
    }
    dp[0][0] = true;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
        }
    }
    if (dp[m][n] == true)
        return 1;
    else
        return 0;
}
