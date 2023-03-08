#include <bits/stdc++.h>
using namespace std;

// SC := O(n)
// TC := O(n +2*E) //For every node we are traversg its all adj nodes....Summmation  of degress = 2E.

class Solution
{
private:
    bool detect(int src, vector<int> adj[], vector<int> vis)
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (it != parent)
                {
                    return true;
                }
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
                if (detect(i, adj, vis))
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