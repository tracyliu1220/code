class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;
    vector<vector<char>> grid;

    void dfs(int x, int y) {
        if (x < 0 || x >= n) return;
        if (y < 0 || y >= m) return;
        if (grid[x][y] != '1') return;
        if (vis[x][y]) return;
        vis[x][y] = true;
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
    }

    int numIslands(vector<vector<char>>& _grid) {
        grid = _grid;
        if (grid.empty()) return 0;
        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
