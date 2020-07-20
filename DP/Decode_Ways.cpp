/* Given a string of digits (0-9), each digit/pair of digits can be 
decoded to a character. Return the number of possibilities of decodings

Approach - Two functions, one which takes a pair and returns 1, if it is 
a valid encoding and the other which does the same with a single digit.
Maintain a memoisation array, top-down, calculate the number of ways for the last 
digit, and keep doing so for all preceding characters.
return dp[0]
*/
int returnDoubleDigit(char a, char b)
{
    int aint = a - '0';
    if (aint == 0)
        aint = 4;
    int bint = b - '0';
    return (10 * aint + bint);
}
int returnSingleInt(char a)
{
    int aint = a - '0';
    return aint;
}
bool getChar(int a)
{
    if (a > 0 && a <= 26)
        return true;
    return false;
}

int Solution::numDecodings(string s)
{
    int n = s.size();
    vector<int> dp(n + 1);
    int i;
    dp[n] = 0;
    dp[n - 1] = (getChar(returnSingleInt(s[n - 1]))) ? 1 : 0;
    for (i = n - 2; i >= 0; i--)
    {
        if (getChar(returnSingleInt(s[i])))
            dp[i] += dp[i + 1];
        if (i + 2 < n && getChar(returnDoubleDigit(s[i], s[i + 1])))
            dp[i] += dp[i + 2];
        else if (i + 2 == n && getChar(returnDoubleDigit(s[i], s[i + 1])))
            dp[i]++;
    }
    return dp[0];
}
