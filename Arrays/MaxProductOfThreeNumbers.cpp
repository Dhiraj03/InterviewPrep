/*
Given an array of integers, find the maximum product of three elements
in an array.
Approach - Either sort the array, return the max of the product of the 3 largest elements
and product of two smallest elements and largest element.
Or separate variables could be maintained for the same purpose.
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
        int n = nums.size();
        int high = nums[n-1]*nums[n-2]*nums[n-3];
        int low = 0;
        if(nums[0] <0 && nums[1] < 0)
            low = nums[0]*nums[1]*nums[n-1];
        return max(low,high);
    }
};