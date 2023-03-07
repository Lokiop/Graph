#include <bits/stdc++.h>
using namespace std;

// Space Complexity = O(3*n) = O(n)
// Time Complexity = O(V) + O(E)
vector<int> bfsOfGraph(int v, vector<int> adj[])
{
    // Code here
    vector<bool> vis(v, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    vector<int> ans;
    while (!q.empty())
    {
        int p = q.front();
        ans.push_back(p);
        q.pop();
        for (auto i : adj[p])
        {
            if (!vis[i])
            {
                vis[i] = true;
                q.push(i);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}