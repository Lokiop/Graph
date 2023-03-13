#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool check(int s, vector<int> adj[], vector<int> &color)
    {
        queue<int> q;
        color[s] = 0;
        q.push(s);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(int v, vector<int> adj[])
    {
        // Code here
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (!check(i, adj, color))
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}