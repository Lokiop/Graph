#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
    string topoSort(vector<int> &indegree, vector<vector<int>> &adj, int n)
    {
        queue<int> q;
        string ans;
        for (int i = 0; i < n; i++)
        {
            if (!indegree[i])
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans += node + 'a';
            for (auto &it : adj[node])
            {
                indegree[it]--;
                if (!indegree[it])
                    q.push(it);
            }
        }

        return ans;
    }

public:
    string findOrder(string dict[], int n, int k)
    {
        vector<vector<int>> adj(k);
        vector<int> indegree(k, 0);

        for (int i = 1; i < n; i++)
        {
            string a = dict[i - 1];
            string b = dict[i];
            for (int j = 0; j < min(a.size(), b.size()); j++)
            {
                if (a[j] != b[j])
                {
                    adj[a[j] - 'a'].push_back(b[j] - 'a');
                    indegree[b[j] - 'a']++;
                    break;
                }
            }
        }

        return topoSort(indegree, adj, k);
    }
};