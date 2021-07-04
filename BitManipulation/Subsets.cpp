/* Same as subsets (backtracking) - return the power set of the array given.
Approach : Maintain a counter, and each bit of the counter (total n bits) will represent the 
state of the current subset - if the bit at a particular position is set, then this
element will be included in the subset, continue this till the end of the array,
till the counter equals all possible combinations - 2^n
*/
class Solution
{
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int total = pow(2, n);
        int i, j;
        vector<int> tempResult;
        for (i = 0; i < total; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    tempResult.push_back(nums[j]);
            }
            res.push_back(tempResult);
            tempResult.clear();
        }
        return res;
    }
};