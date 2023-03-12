#include <bits/stdc++.h>
using namespace std;

// SC := O(n*m)
// TC := O(n*m)

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int r, int c, int newColor)
    {
        // Code here
        int n = image.size();
        int m = image[0].size();

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        queue<pair<int, int>> q;
        q.push({r, c});
        int color = image[r][c];

        image[r][c] = newColor;
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == color && image[nr][nc] != newColor)
                {
                    q.push({nr, nc});
                    image[nr][nc] = newColor;
                }
            }
        }

        return image;
    }
};

int main()
{

    return 0;
}