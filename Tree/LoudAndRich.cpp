class Solution
{
public:
    int dfs(vector<vector<int>> &richer, vector<int> &quiet, vector<vector<int>> &neighbours, int index, vector<int> &answer)
    {
        int n = quiet.size();
        int i;
        int val;
        if (answer[index] != -1)
            return answer[index];
        int min = index;
        for (i = 0; i < neighbours[index].size(); i++)
        {
            val = dfs(richer, quiet, neighbours, neighbours[index][i], answer);
            if (quiet[val] < quiet[min])
                min = val;
        }
        return min;
    }

    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int n = quiet.size();
        int m = richer.size();
        int i;
        vector<vector<int>> neighbours(n);
        for (i = 0; i < m; i++)
        {
            neighbours[richer[i][1]].push_back(richer[i][0]);
        }

        vector<int> answer(n);
        for (i = 0; i < n; i++)
        {
            answer[i] = -1;
        }

        for (i = 0; i < n; i++)
        {

            answer[i] = dfs(richer, quiet, neighbours, i, answer);
        }
        return answer;
    }
};