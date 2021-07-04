/*given a string a list of words as a dictionary - return true if the string can be formed as a concatenation
of the words in the dictionary - else return false.
Approach :  Simple DP with memoisation through a boolean array.
*/
class Solution
{
public:
    bool canBreak(string s, int index, vector<string> &wordDict, vector<bool> &dp)
    {
        int i = index;
        int j;
        int n = s.size();
        int m = wordDict.size();
        for (; i < n; i++)
        {
            string temp = s.substr(index, (i - index + 1));
            cout << temp << endl;
            bool present = false;
            for (j = 0; j < m; j++)
            {
                if (temp == wordDict[j])
                {
                    present = true;
                    break;
                }
            }
            if (present && dp[i + 1])
            {
                cout << "found";
                return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        int i;
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[n] = true;
        for (i = n - 1; i >= 0; i--)
        {
            if (canBreak(s, i, wordDict, dp))
                dp[i] = true;
            else
                dp[i] = false;
        }
        return dp[0];
    }
};