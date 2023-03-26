#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int s, vector<int> &vis, vector<int> &dist,
             vector<int> &adj, int &ans, int distance)
    {
        vis[s] = 1;
        dist[s] = distance;
        int next = adj[s];

        if (next != -1)
        {
            if (!vis[next])
            {
                dfs(next, vis, dist, adj, ans, distance + 1);
            }
            else if (vis[next] == 1)
            {
                ans = max(ans, distance - dist[next] + 1);
            }
        }

        vis[s] = 2;
        return;
    }

public:
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<int> vis(n, 0);
        vector<int> dist(n, 0);
        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, dist, edges, ans, 0);
            }
        }

        return ans;
    }
};