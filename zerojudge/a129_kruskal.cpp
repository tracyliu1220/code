#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct Edge {
    int u, v; LL w;
};

vector<int> pa;
int find(int x) {
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}
void merge(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x != y)
        pa[x] = y;
}

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, m; while (cin >> n >> m) {
        vector<Edge> edges;
        for (int i = 0 ; i < m ; i++) {
            int u, v; LL w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }
        sort(edges.begin(), edges.end(), cmp);

        pa.clear(); pa.resize(n);
        for (int i = 0 ; i < n ; i++)
            pa[i] = i;

        LL ans = 0;
        int cnt = 0;
        for (int i = 0 ; i < m ; i++) {
            Edge e = edges[i];
            if (find(e.u) != find(e.v))
                ans += e.w, merge(e.u, e.v), cnt++;
        }
        
        if (cnt != n - 1)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
}
