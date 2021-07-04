/*
Given an array of integers, return the index of any peak element - 
A peak element is an element that is larger than both its neighbours - nums[-1] = nums[n] = INF
Approach : Binary Search Solution - Check the middle element - if it is larger
than both its neighbours, return it, else
check if (nums[mid] > nums[mid+1])
  end = mid-1;
else
  start = mid+1
unless mid == 0 or mid == n-1
and larger than their neighbours - return them
*/
class Solution {
public:
    int findPeakElement(vector<int>& A) {
        if(A.size() == 1)
            return 0;
        int start,end,mid;
        start = 0;
        end = A.size();
        int n = A.size();
        while(start <= end)
        {
            mid = (start+end)/2;
            if(mid == 0 && A[mid] > A[mid+1])
                return 0;
            else if(mid == 0)
                start = mid+1;
            else if(mid == n-1 && A[mid] > A[mid-1])
                return mid;
            else if(mid == n-1)
                end = mid-1;
            else if(A[mid] > A[mid+1] && A[mid] > A[mid-1])
                return mid;
            else if(A[mid] > A[mid+1])
                end = mid-1;
            else 
                start = mid+1;
        }
        return -1;
    }
};