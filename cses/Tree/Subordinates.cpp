#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int n;
Graph g;
vector<int> ans;

void dfs(int u) {
    ans[u] = 1;
    for (int v : g[u]) {
        dfs(v);
        ans[u] += ans[v];
    }
}

int main() {
    cin >> n;
    g = Graph(n + 1);

    for (int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        g[par].push_back(i);
    }
    ans = vector<int>(n + 1);
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] - 1 << (i == n ? '\n' : ' ');
    }
    return 0;
}
