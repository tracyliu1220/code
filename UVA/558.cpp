#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;

struct Edge { int u, v; LL w; };

void relax(Edge &e, vector<LL> &dis) {
    dis[e.v] = min(dis[e.v], dis[e.u] + e.w);
}
void BellmanFord(int s, vector<LL> &dis, vector<Edge> &edges) {
    int n = dis.size();
    int m = edges.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            relax(edges[j], dis);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        vector<Edge> edges;
        for (int i = 0; i < m; i++) {
            int u, v; LL w; cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }
        
        vector<LL> dis(n, INF);
        BellmanFord(0, dis, edges);
        vector<LL> dis_tmp = dis;
        BellmanFord(0, dis, edges);
        if (dis != dis_tmp)

            cout << "possible\n";
        else
            cout << "not possible\n";
    }
}
