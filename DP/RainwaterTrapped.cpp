/*
Given an array of integers, each representing the height of a building at the respecitve position - 
return the total amount of rainwater trapped in between the buildings.
Approach  (I think two-pointer approach is better) - DP - Prefix-Suffix method - 
For every index, pre-compute the heights of the largest buildings on the right and left sides of it - 
prefix[0] = height[0] and suffix[n-1] = height[n-1], then for every i,
prefix[i] =  max(height[i], prefix[i-1])
suffix[i] = max(height[i], suffix[i+1])
For every index, 
 res += min(prefix[i], suffix[i]) - height[i]
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <=2)
            return 0;
        int n = height.size();
        int i;
        vector<int> suffix(n);
        vector<int> prefix(n);
        suffix[n-1] = height[n-1];
        prefix[0] = height[0];
        for(i = 1;i<n;i++)
        {
            prefix[i] = max(height[i], prefix[i-1]); 
        }
        for(i=n-2;i>=0;i--)
        {
            suffix[i] = max(height[i], suffix[i+1]);
        }
        int res = 0;
        for(i=0;i<n;i++)
        {
            res += min(suffix[i], prefix[i])-height[i];
        }
        return res;
    }
};