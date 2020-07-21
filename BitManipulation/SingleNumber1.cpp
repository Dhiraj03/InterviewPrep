
/* Given an array where every element except one appears twice,
find the element that occurs once.
Appraoch - XOR all elements of the array, return th result (Since a ^ a =0)
*/
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        return res;
    }
};