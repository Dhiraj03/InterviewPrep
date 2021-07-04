/* Book allocation(IB) /Shipping weights(LC)
Approach - Binary Search - the start is the max in the array and the end is
the sum of all elements in the array - for every middle element,
check if this satisfies the condition, if it does, move to the left, if it
doesnt, move to the right
*/
class Solution
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    bool isPossible(vector<int> &weights, int max, int D)
    {
        int days = 1;
        int i;
        int currSum = 0;
        int n = weights.size();
        for (i = 0; i < n; i++)
        {
            if (weights[i] > max)
                return false;
            if (currSum + weights[i] > max)
            {
                currSum = weights[i];
                days++;
                if (days > D)
                    return false;
            }
            else
                currSum += weights[i];
        }
        return true;
    }

    int findMinimumDays(vector<int> &weights, int D)
    {
        int n = weights.size();
        int start = 0;
        int end = 0;
        int i;
        for (i = 0; i < n; i++)
        {
            start = max(start, weights[i]);
            end += weights[i];
        }
        int mid;
        int res = end;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (isPossible(weights, mid, D))
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return res;
    }

    int shipWithinDays(vector<int> &weights, int D)
    {
        int n = weights.size();
        int res = findMinimumDays(weights, D);
        return res;
    }
};