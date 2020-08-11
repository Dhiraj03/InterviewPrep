/*
Given an array of integers - replace every element with the product of all 
the other elements in the array - WITHOUT using the division operator - 
in O(n)
Approach :  Use Simple DP to maintain a prefix and suffix array which for each index i,
maintain the product of all elements before and after i respectively
*/
class Solution {
public:
    
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = 1;
        int i;
        for(i=1;i<n;i++)
        {
            prefix[i] = nums[i-1]*prefix[i-1];
        }
        suffix[n-1] = 1;
        for(i=n-2;i>=0;i--)
        {
            suffix[i] = nums[i+1] * suffix[i+1];
        }
        vector<int> res;
        for(i=0;i<n;i++)
        {
            res.push_back(prefix[i]*suffix[i]);
        }
        return res;
    }
};