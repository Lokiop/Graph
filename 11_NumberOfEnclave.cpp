#include <bits/stdc++.h>
using namespace std;

// SC := O(n*m)
// TC := O(n*m)

class Solution
{
public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m));
        int cnt = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = 0;
                if (grid[i][j] == 1)
                {
                    cnt++;
                    if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                        cnt--;
                    }
                }
            }
        }

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int r = row + dx[i];
                int c = col + dy[i];

                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !vis[r][c])
                {
                    vis[r][c] = 1;
                    cnt--;
                    q.push({r, c});
                }
            }
        }

        return cnt;
    }
};

int main()
{

    return 0;
}