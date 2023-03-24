#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), check(n, 0), ans;
        queue<int> q;

        // reverse the edges as kahn's algo works on indegree
        for (int i = 0; i < n; i++)
        {
            for (auto &it : graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!indegree[i])
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            check[node] = 1;
            for (auto &it : adj[node])
            {
                indegree[it]--;
                if (!indegree[it])
                    q.push(it);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (check[i])
                ans.push_back(i);
        }

        return ans;
    }
};