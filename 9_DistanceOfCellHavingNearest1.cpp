#include <bits/stdc++.h>
using namespace std;

// SC := O(n)
// TC := O(n) + O(v + 2*E)

class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        vector<vector<int>> dist(n, vector<int>(m));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
                else
                {
                    dist[i][j] = -1;
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int r = row + dx[i];
                int c = col + dy[i];

                if (r >= 0 && r < n && c >= 0 && c < m && dist[r][c] == -1)
                {
                    q.push({r, c});
                    dist[r][c] = dist[row][col] + 1;
                }
            }
        }

        return dist;
    }
};

int main()
{

    return 0;
}