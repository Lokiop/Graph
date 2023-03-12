#include <bits/stdc++.h>
using namespace std;

// SC := O(n*m)
// TC := O(n*m)

class Solution
{
    void bfs(int r, int c, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &vis)
    {
        vis[r][c] = 1;

        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int nrow = row + i;
                    int ncol = col + j;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                    {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    cnt++;
                    bfs(i, j, n, m, grid, vis);
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