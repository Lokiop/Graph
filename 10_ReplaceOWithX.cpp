#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    void bfs(int n, int m, vector<vector<char>> &mat, vector<vector<char>> &ans)
    {
        ans[n][m] = 'O';
        queue<pair<int, int>> q;
        q.push({n, m});

        n = ans.size();
        m = ans[0].size();
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int r = row + dx[i];
                int c = col + dy[i];

                if (r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == 'O' && ans[r][c] == 'X')
                {
                    ans[r][c] = 'O';
                    q.push({r, c});
                }
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> ans(n, vector<char>(m, 'X'));
        for (int j = 0; j < m; j++)
        {
            if (mat[0][j] == 'O' && ans[0][j] == 'X')
            {
                bfs(0, j, mat, ans);
            }

            if (mat[n - 1][j] == 'O' && ans[n - 1][j] == 'X')
            {
                bfs(n - 1, j, mat, ans);
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (mat[i][0] == 'O' && ans[i][0] == 'X')
            {
                bfs(i, 0, mat, ans);
            }

            if (mat[i][m - 1] == 'O' && ans[i][m - 1] == 'X')
            {
                bfs(i, m - 1, mat, ans);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}