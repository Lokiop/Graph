#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[])
    {
        // code here
        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++)
        {
            for (auto &it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (!indegree[i])
                q.push(i);
        }

        int count = 0;

        while (!q.empty())
        {
            int s = q.front();
            q.pop();
            count++;
            for (auto &it : adj[s])
            {
                indegree[it]--;
                if (!indegree[it])
                    q.push(it);
            }
        }

        return count != v;
    }
};