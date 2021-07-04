/* Given a string, return all possible palindromic decompositions of the string, 
arranged in ascending order of lengths of constituents.
Approach : Simple backtracking - From the starting index of the string, explore every substring, 
check if it is a palindrome, add it to a temp vector of strings, and then recurse,
with index incremented - when index == n, then add the temporary vector to result.
*/
class Solution
{
public:
    bool checkPalindrome(string snippet)
    {
        int i;
        int n = snippet.size();
        for (i = 0; i < n / 2; i++)
        {
            if (snippet[i] != snippet[n - i - 1])
                return false;
        }
        return true;
    }

    void partitionString(string A, int index, vector<string> &temp, vector<vector<string>> &res)
    {
        int n = A.size();
        if (index == n)
        {
            res.push_back(temp);
            return;
        }
        int i;
        for (i = index; i < n; i++)
        {
            if (checkPalindrome(A.substr(index, (i - index + 1))))
            {
                temp.push_back(A.substr(index, (i - index + 1)));
                partitionString(A, i + 1, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string A)
    {
        vector<string> temp;
        vector<vector<string>> res;
        partitionString(A, 0, temp, res);
        return res;
    }
};