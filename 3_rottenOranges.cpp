#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cntFresh = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
                vis[i][j] = 1;
            }
            else if (grid[i][j] == 1)
            {
                cntFresh++;
            }
        }
    }

    int t = -1;
    int cnt = 0;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + dx[i];
                int ncol = c + dy[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    cnt++;
                }
            }
        }
        t++;
    }

    if (cnt != cntFresh)
        return -1;

    return t;
}

int main()
{

    return 0;
}