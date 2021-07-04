/* Given an array of integers - the value of the element at index i represents
the maximum jump from that position - determine if you can start at the 0th index
and reach the last index.
Approrach - Simple DP - Top-down - dp[n-1] = TRUE
For every preceding element, run a loop on all indices that can be reached, as 
soon as we encounter an index from where we can reach the last index, break.
return dp[0]
*/

int Solution::canJump(vector<int> &A)
{
    int n = A.size();
    int i;
    vector<bool> dp(n);
    dp[n - 1] = true;
    for (i = n - 2; i >= 0; i--)
    {
        dp[i] = false;
        for (int j = i; j <= (i + A[i]); j++)
        {
            if (dp[j])
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[0] ? 1 : 0;
}
