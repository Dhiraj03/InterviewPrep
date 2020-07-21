/*
Given an array, find the minimum XOR value between any pair of elements - 
Approach : The XOR is the lowest between adjancent elements in a sorted array -
Proof - lets say the min XOR is A ^ B, where there is some C, A<C<B,
The first index at which A and B differ - let that be i - 
then C[i] = 0 => A and C have lower xor, if C[i] =1 => B and C have lower XOR - 
Proved by contradiction
*/
int Solution::findMinXor(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = A.size();
    int min = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if ((A[i] ^ A[i + 1]) < min)
            min = A[i] ^ A[i + 1];
    }
    return min;
}
