/* Given an array where each element except once, appears thrice,
return the element that occurs once.
Approach :
Every bit is counted thrice for all elements except one.
Find the total count of set ith bits for every number of the array - and mod by 3
Keep adding the ith power of this to the result.
*/

int Solution::singleNumber(const vector<int> &A)
{
    int i, j;
    int count = 0;
    int n = A.size();
    int res = 0;
    for (i = 0; i < 32; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            if (A[j] & (1 << i))
                count++;
        }
        count = count % 3;

        if (count == 1)
            res += (1 << i);
    }
    return res;
}
