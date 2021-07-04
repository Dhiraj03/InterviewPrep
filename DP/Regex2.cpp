/*
Basic regex matching - 
1. '.' means any single character
2. '*' means zero or more occurrences of the preceding character

Approach : dp[i][j] will indicate whether s[0..i-1] matches with p[0...j-1]
1. dp[0][0] = true
2. for dp[0][i], if the preceding characters are <char>*, then dp[0][i] = dp[0][i-2]

3. For every element, if 
  a. s[i-1] == p[j-1] or p[j-1] == true
     dp[i][j] = dp[i-1][j-1]
  b. else if p[j-1] = '*',
      dp[i][j] = dp[i][j-2] in case of zero occurrences
      if(p[j-2] == s[i-1] or p[j-2] == '.')
        then dp[i][j] = dp[i][j] (in case it was set above)|| dp[i-1][j]
        
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        int i,j;
        vector<vector<bool>> dp(m+1);
        for(i=0;i<=m;i++)
        {
            dp[i].resize(n+1);
        }
        
                dp[0][0] = true;

        for(i=1;i<=n;i++)
        {
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-2];
        }
        
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                {
                    
                    dp[i][j] = dp[i][j-2];
                    
                if(s[i-1] == p[j-2] || p[j-2] == '.')
                        dp[i][j] = dp[i-1][j] || dp[i][j];
                }
            }
        }
        return dp[m][n];
    }
};