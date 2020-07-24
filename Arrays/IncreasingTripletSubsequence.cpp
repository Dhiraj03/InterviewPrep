/* Given an array of unsorted integers - return true if it contains an 
increasing subsequence of size 3
*/
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int count;
        int n = nums.size();
        int i, j;
        if (n <= 2)
            return false;
        int a = nums[0];
        int b = INT_MAX;
        for (i = 1; i < n; i++)
        {
            if (nums[i] < a)
                a = nums[i];

            else if (nums[i] > a && nums[i] < b)
            {
                b = nums[i];
            }
            else if (nums[i] > b && b != -1000)
                return true;
        }
        return false;
    }
};