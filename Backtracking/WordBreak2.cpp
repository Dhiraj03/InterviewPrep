class Solution
{
public:
    void canBreak(string s, int index, vector<string> &wordDict, vector<string> &res, string temp)
    {

        int n = s.size();
        if (index == n)
        {
            res.push_back(temp);
            return;
        }
        int m = wordDict.size();
        for (int i = index; i < n; i++)
        {
            string tempStr = s.substr(index, (i - index + 1));
            for (int j = 0; j < m; j++)
            {
                if (tempStr == wordDict[j])
                {
                    if (*(temp.end() - 1) != ' ' && temp.size() != 0)
                        temp = temp + " ";
                    temp = temp + tempStr;
                    canBreak(s, i + 1, wordDict, res, temp);
                    temp = temp.substr(0, (temp.size() - i + index - 1));
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> res;
        string temp = "";
        canBreak(s, 0, wordDict, res, temp);
        // sort(res.begin(), res.end());
        return res;
    }
};