#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> dis(n, vector<int>(n, -1));
    queue<pair<int, int>> que;
    if (grid[1][1] != '#') {
        dis[1][1] = 1;
        que.push({1, 1});
    }
    while (que.size()) {
        pair<int, int> u = que.front();
        que.pop();

        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int nx = u.first + dx[i];
            int ny = u.second + dy[i];
            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= n) continue;
            if (grid[nx][ny] == '#') continue;
            if (dis[nx][ny] != -1) continue;
            dis[nx][ny] = dis[u.first][u.second] + 1;
            que.push({nx, ny});
        }
    }
    if (dis[n - 2][n - 2] == -1) {
        cout << "No solution!" << '\n';
    } else {
        cout << dis[n - 2][n - 2] << '\n';
    }
}
