#include <bits/stdc++.h>
using namespace std;

// Considering 3 states for a node
// 0 = Not visited
// 1 = Processing
// 2 = Processed
class Solution
{
    bool dfs(int s, vector<int> &vis, vector<int> adj[])
    {
        vis[s] = 1;
        for (auto &it : adj[s])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, adj) == true)
                {
                    return true;
                }
            }
            else if (vis[it] == 1)
                return true;
        }

        vis[s] = 2;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[])
    {
        // code here
        vector<int> vis(v, 0);

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, adj) == true)
                    return true;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}