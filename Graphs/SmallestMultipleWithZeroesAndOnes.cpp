/* Given an integer N, return the smallest multiple of N that can be formed using
only 1s and 0s.
Appraoch :  BFS (TLE on IB) - Start with the string "1", enqueue it, check if remainder
is 0 - return the string, else if the remainder is unique (maintain a set of all remainders),
then insert the remainder into the set and enqueue str + "1"  and str + "0".
If two numbers x and y have the same remainders - then when z is concatenated at the end, 
both xz and yz will give same remainder - so storing just one of them - the smaller one, will be 
enough.
*/
int rem(string t, int N)
{
    int i;
    int r = 0;
    for (i = 0; i < t.size(); i++)
    {
        r = r * 10 + (t[i] - '0');
        r %= N;
    }
    return r;
}

string Solution::multiple(int A)
{
    string start = "1";
    set<int> visited;
    queue<string> q;
    q.push(start);
    int r;
    string src;
    while (!q.empty())
    {
        start = q.front();
        q.pop();
        r = rem(start, A);
        if (r == 0)
            return start;
        else if (visited.find(r) == visited.end())
        {
            visited.insert(r);
            q.push(start + '0');
            q.push(start + '1');
        }
    }
}
