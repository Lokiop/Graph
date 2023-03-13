#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int s, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[s] = 1;
        for (auto &it : adj[s])
        {
            if (!vis[it])
            {
                dfs(it, vis, st, adj);
            }
        }

        st.push(s);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int v, vector<int> adj[])
    {
        // code here
        vector<int> vis(v, 0);
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

int main()
{

    return 0;
}