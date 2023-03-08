#include <bits/stdc++.h>
using namespace std;

// SC := O(n)
// TC := O(n) + O(v + 2*E)

class Solution
{
    void dfs(int s, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[s] = 1;
        for (auto it : adj[s])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        vector<vector<int>> g(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, vis, g);
            }
        }

        return cnt;
    }
};

int main()
{

    return 0;
}