#include <bits/stdc++.h>
using namespace std;

// SC := O(n * m)
// TC := O(n * m)

class Solution
{
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis,
             vector<pair<int, int>> &vec, int row0, int col0, int n, int m)
    {
        vis[row][col] = 1;
        vec.push_back({row - row0, col - col0});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++)
        {
            int r = row + dx[i];
            int c = col + dy[i];
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] && !vis[r][c])
            {
                dfs(r, c, grid, vis, vec, row0, col0, n, m);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j])
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j, n, m);
                    st.insert(vec);
                }
            }
        }

        return st.size();
    }
};

int main()
{

    return 0;
}