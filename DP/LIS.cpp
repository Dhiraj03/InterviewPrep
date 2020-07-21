/*
Given an unsorted array - return the length of the longest increasing subsequence - 
Maintain a memoisation array, dp, that for index i, stores the length of the longest increasing
subsequence in arr[0...i] and includes arr[i].
dp[i] for all i = 1, initially,
from i = 1 to n-1
For every i, run a loop from 0 to i-1, and check whether that element is greater than the counter element
if it is - and dp[j] + 1 >  dp[i], dp[i];
return the maximum value in dp
*/
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int i, j;
        vector<int> dp(n);
        dp[0] = 1;
        int max = 1;
        for (i = 1; i < n; i++)
        {
            dp[i] = 1;
            for (j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                        dp[i] = dp[j] + 1;
                }
            }
            cout << dp[i] << endl;
            if (dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};