class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dis(n, vector<int>(m, -1));

        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    dis[i][j] = 0;
                    que.push({i, j});
                }
            }
        }

        while (que.size() > 0) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            vector<pair<int, int>> np = {
                {x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
            for (pair<int, int> p : np) {
                int nx = p.first;
                int ny = p.second;
                if (nx < 0 || nx >= n) continue;
                if (ny < 0 || ny >= m) continue;
                if (dis[nx][ny] != -1) continue;
                dis[nx][ny] = dis[x][y] + 1;
                que.push({nx, ny});
            }
        }

        return dis;
    }
};
