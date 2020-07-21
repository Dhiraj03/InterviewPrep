/* Given an array where every element except one appears twice,
find the element that occurs once.
Appraoch - XOR all elements of the array, return th result (Since a ^ a =0)
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
