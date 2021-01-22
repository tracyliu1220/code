#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
struct Edge {
  int v; LL w;
};
struct State {
  int idx; LL val;
  bool operator > (const State &rhs) const {
    return val > rhs.val;
  }
};
vector<vector<Edge>> G;
vector<LL> dis;
vector<bool> visited;
LL Prim(int s) {
  priority_queue<State, vector<State>, greater<State>> pq;
  dis[s] = 0; pq.push({s, dis[s]});
  LL ans = 0;
  while (pq.size()) {
    State p = pq.top(); pq.pop();
	int u = p.idx, val = p.val;
    if (dis[u] < val) continue;
    if (!visited[u]) {
      ans += val;
      visited[u] = true;
    }
    for (int i = 0; i < G[u].size(); i++) {
      Edge e = G[u][i];
      if (dis[e.v] > e.w) {
        dis[e.v] = e.w;
        pq.push({e.v, dis[e.v]});
      }
    }
  }
  return ans;
}
int main() {
    int n, m; while (cin >> n >> m) {
        G.clear();
        G.assign(n, {});
        while (m--) {
            int u, v; LL w;
            cin >> u >> v >> w;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dis.assign(n, INF);
        visited.assign(n, false);
        LL ans = Prim(0);
        bool ok = true;
        for (auto &v : dis)
            if (v == INF)
                ok = false;
        if (ok)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }
}
