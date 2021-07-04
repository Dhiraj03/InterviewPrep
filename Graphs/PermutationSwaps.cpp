/*Given two permutations of the set of numbers from 1...N, along with
a set of good pairs (size M array) - find whether the second permutation 
can be obtained from the first one by swapping only good pairs (listed as 1-indexed indices)
Approach : Simple DSU - Apply DSU on the good-pair array, will end up with sets, where any index
can be swapped with the other within the set, have a hash map from element to index+1 (since it is 1-indexed),
run a loop, if find(index[A[i]]) != find(index[B[i]]), then the two indices don't belong to the same set,
and the second permutation cannot be formed.
*/
int find(vector<int> &parent, int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void dsUnion(vector<int> &parent, vector<int> &rank, int a, int b)
{
    int ap = find(parent, a);
    int bp = find(parent, b);
    if (ap == bp)
        return;
    if (rank[ap] > rank[bp])
    {
        parent[bp] = ap;
        rank[ap] += rank[bp];
    }
    else
    {
        parent[ap] = bp;
        rank[bp] += rank[ap];
    }
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int>> &C)
{
    int i, j;
    int n = A.size();
    int m = C.size();
    vector<int> parent(n + 1, -1);
    vector<int> rank(n + 1, 1);
    for (i = 0; i < m; i++)
    {
        dsUnion(parent, rank, C[i][0], C[i][1]);
    }

    map<int, int> index;
    for (i = 0; i < n; i++)
    {
        index[A[i]] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        if (find(parent, index[A[i]]) != find(parent, index[B[i]]))
            return 0;
    }
    return 1;
}
