/*
Given an array of integers - return the maximum product of the elements
in a subarray
Approach - Start with the first element as the maximum.
And maintain two separate min and max (initially equal to the global max)
Run a loop - if the element is negative, then swap the min and max - and update 
the min and max as min = min(imin*A[i], A[i]) and max = max(imax*A[i], A[i])
and update the global maximum as max(global_max, imax)
*/
class Solution {
public:
    void swap(int&a, int&b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int imin = res,imax=res;
        int n = nums.size();
        int i =1;
        while(i < n)
        {
            
            if(nums[i] < 0)
                swap(imin,imax);
            imin = min(imin*nums[i], nums[i]);
            imax = max(imax*nums[i], nums[i]);
            res = max(res,imax);
            i++;
        }
        return res;
    }
};