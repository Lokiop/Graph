#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution
{
    void topoSort(int s, vector<int> &vis, stack<int> &st, vector<vector<pair<int, int>>> &adj)
    {
        vis[s] = 1;
        for (auto &it : adj[s])
        {
            if (!vis[it.first])
            {
                topoSort(it.first, vis, st, adj);
            }
        }

        st.push(s);
    }

public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                topoSort(i, vis, st, adj);
            }
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (dist[node] != INT_MAX)
            {
                for (auto &it : adj[node])
                {
                    if (dist[node] + it.second < dist[it.first])
                    {
                        dist[it.first] = dist[node] + it.second;
                    }
                }
            }
            else
            {
                dist[node] = -1;
            }
        }

        return dist;
    }
};