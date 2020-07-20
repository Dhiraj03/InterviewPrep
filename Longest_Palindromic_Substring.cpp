// Given a string, return the  longest palindromic substring (contiguous)

/* Approach - For every character in the string, look for a palindrome centered at i, or centered at
i  and  i+1. Calculate the length of these palindromes, and if the length is greater than the maximum value 
(seen till that point), update the start and end index. Return the string enclosed by start and end (inclusive).
Time - O(n^2)
*/

class Solution
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    string longestPalindrome(string s)
    {
        if (s.size() == 0)
            return "";
        int n = s.size();
        int start = 0;
        int end = 0;
        int len1, len2, len, i;
        for (i = 0; i < n; i++)
        {
            len1 = expandFromMiddle(s, i, i);
            len2 = expandFromMiddle(s, i, i + 1);
            len = max(len1, len2);
            if (len > end - start)
            {
                start = i - ((len - 1) / 2);
                end = i + (len / 2);
            }
        }
        string res;
        for (i = start; i <= end; i++)
        {
            res.push_back(s[i]);
        }
        return res;
    }
    int expandFromMiddle(string s, int left, int right)
    {
        if (s.size() == 0 || left > right)
            return 0;
        while (left >= 0 && right <= s.size() - 1 && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};