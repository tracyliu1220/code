#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n;
vector<int> G[MAXN];
int dp[MAXN][2];

void init() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u, int par) {
    dp[u][0] = 0;
    dp[u][1] = 0;
    int a = 0, b = 0;
    for (int v : G[u]) {
        if (v != par) {
            dfs(v, u);
            dp[u][0] += dp[v][1];
            b = max(a + dp[v][0] + 1, b + dp[v][1]);
            a += dp[v][1];
        }
    }
    dp[u][1] = max(dp[u][0], b);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    init();
    dfs(1, 0);
    cout << dp[1][1] << '\n';
}
