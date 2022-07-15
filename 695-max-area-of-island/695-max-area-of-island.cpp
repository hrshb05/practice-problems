class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int ans = 0;
      vector<vector<bool>> v(grid.size(), vector<bool>(grid[0].size(), false));
      for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
          if (grid[i][j] == 0 || v[i][j])
            continue;
          // bfs
          int area = 0;
          queue<pair<int, int>> q;
          q.push({i, j});
          while (!q.empty()) {
            pair<int, int> c = q.front();
            q.pop();
            if (v[c.first][c.second])
              continue;
            v[c.first][c.second] = true;
            area++;
            for (auto& d : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
              int ii = c.first + d.first, jj = c.second + d.second;
              if (ii < 0 || ii >= grid.size() || jj < 0 || jj >= grid[i].size())
                continue;
              if (grid[ii][jj] == 1 && !v[ii][jj])
                q.push({ii, jj});
            }
          }
          ans = max(ans, area);
        }
      }
      return ans;
    }
};