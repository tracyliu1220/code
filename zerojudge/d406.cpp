#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int S;
    int T = 1;
    while (cin >> S) {
        int n, m;
        cin >> n >> m;
        
        vector<int> G[n];
        int tmp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> tmp;
                G[i].push_back(-tmp);
            }
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            if (G[0][i] == -1) {
                G[0][i] = 1;
                q.push({0, i});
            }
        }

        while (q.size()) {
            pair<int, int> cur = q.front();
            q.pop();

            int i = cur.first;
            int j = cur.second;

            // left
            if (j - 1 >= 0 && G[i][j - 1] == -1) {
                G[i][j - 1] = G[i][j] + 1;
                q.push({i, j - 1});
            }
            // right
            if (j + 1 < m && G[i][j + 1] == -1) {
                G[i][j + 1] = G[i][j] + 1;
                q.push({i, j + 1});
            }
            // down
            if (i + 1 < n && G[i + 1][j] == -1) {
                G[i + 1][j] = G[i][j] + 1;
                q.push({i + 1, j});
            }

            // up
            if (S == 2) continue;
            if (i - 1 >= 0 && G[i - 1][j] == -1) {
                G[i - 1][j] = G[i][j] + 1;
                q.push({i - 1, j});
            }
        }

        cout << "Case " << T++ << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (G[i][j] == -1) G[i][j] = 0;
                cout << G[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}
