#include <bits/stdc++.h>
using namespace std;

// SC := O(n)
// TC := O(n +2*E) //For every node we are traversg its all adj nodes....Summmation  of degress = 2E.

class Solution
{
private:
    bool dfs(int src, int parent, vector<int> adj[], vector<int> vis)
    {
        vis[src] = 1;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                if (dfs(it, src, adj, vis))
                    return true;
            }
            else if (it != parent)
            {
                return true;
            }
        }

        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, adj, vis))
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