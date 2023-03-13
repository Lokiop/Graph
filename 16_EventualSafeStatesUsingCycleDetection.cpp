#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
    bool dfs(int s, vector<int> &vis, vector<int> &check, vector<int> adj[])
    {
        vis[s] = 1;
        for (auto &it : adj[s])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, check, adj))
                    return true;
            }
            else
            {
                if (vis[it] == 1)
                    return true;
            }
        }

        vis[s] = 2;
        check[s] = 1;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[])
    {
        // code here
        vector<int> vis(v, 0);
        vector<int> ans;
        vector<int> check(v, 0);

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, check, adj);
            }
        }

        for (int i = 0; i < v; i++)
        {
            if (check[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}