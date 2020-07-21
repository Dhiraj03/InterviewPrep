/*
  Find the sqrt of a number (floor(sqrt(x))) if x is not a perfect square using
  binary search.
  Approach :
  Run a loop for 1 to x/2,
  check if mid^2 < x and (mid+1)^2 > x, return mid
*/
class Solution
{
public:
    int mySqrt(int A)
    {
        if (A == 1)
            return 1;
        int start = 1;
        int end = (A / 2);
        while (start <= end)
        {
            long int mid = (start + end) / 2;
            if (mid * mid <= A && (mid + 1) * (mid + 1) > A)
                return mid;
            else if (mid * mid < A)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return 0;
    }
};