/* Given an array of integers, return the power set, sorted internally (within subsets)
and lexicogrpahically sorted.
Approach :  Simple backtracking, after sorting the array,run through every element of the array, two recursive function
calls - one containing the element and other without, when it reaches n (size of the array),
add it to the result vector, and then sort it.
*/

void returnSubsets(vector<int> &A, int index, vector<int> &temp, vector<vector<int>> &finalRes)
{

    int n = A.size();
    if (index == n)
    {
        finalRes.push_back(temp);
        return;
    }
    vector<int> temp_ = temp;
    temp.push_back(A[index]);
    returnSubsets(A, index + 1, temp_, finalRes);
    returnSubsets(A, index + 1, temp, finalRes);
    return;
}

vector<vector<int>> Solution::subsets(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<int> temp;
    vector<vector<int>> finalRes;
    returnSubsets(A, 0, temp, finalRes);
    sort(finalRes.begin(), finalRes.end());
    return finalRes;
}
