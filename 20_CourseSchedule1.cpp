#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int n, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        vector<vector<int>> adj(n);
        for (auto &it : prerequisites)
        {
            adj[it.second].push_back(it.first);
        }

        vector<int> indegree(n);
        for (int i = 0; i < n; i++)
        {
            for (auto &it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (!indegree[i])
                q.push(i);
        }

        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto &it : adj[node])
            {
                indegree[it]--;
                if (!indegree[it])
                    q.push(it);
            }
        }

        return cnt == n;
    }
};