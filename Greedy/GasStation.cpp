/* Given two arrays, A and B, A is the array of fuel available at station i and B is the array of the fuel
reuired to travel from i to i+1. Return the min index that you should start at, to complete a full circuit 
of the gas station - if you can't, return -1;
*/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B)
{

    int netSum = 0;
    int start = 0;
    int n = A.size();
    int totalNetSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalNetSum += (A[i] - B[i]);
    }
    if (totalNetSum < 0)
        return -1;
    for (int i = 0; i < n; i++)
    {
        netSum += (A[i] - B[i]);
        if (netSum < 0)
        {
            netSum = 0;
            start = i + 1;
        }
    }
    return start;
}
