#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int s, int col, vector<int> adj[], vector<int> &color)
    {
        color[s] = col;

        for (auto it : adj[s])
        {
            if (color[it] == -1)
            {
                if (dfs(it, !col, adj, color) == false)
                    return false;
            }
            else if (color[it] == col)
            {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(int v, vector<int> adj[])
    {
        // Code here
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(i, 0, adj, color))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}