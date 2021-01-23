#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Edge {
    int u, v, w;
};


bool relax(Edge e, vector<int> & dis) {
  if (dis[e.u] + e.w < dis[e.v]) {
      dis[e.v] = dis[e.u] + e.w;
      return true;
  }
  return false;
}


bool BellmanFord(int n, vector<Edge> & edges, vector<int> & dis) {
  dis[0] = 0;
  for (int i = 0; i < n - 1; i++) {
	for (int j = 0; j < edges.size(); j++) {
      Edge e = edges[j];
	  relax(e, dis);
    }
  }
  bool flag = false;
  for (int j = 0; j < edges.size(); j++) {
      Edge e = edges[j];
      flag |= relax(e, dis);
  }
  return flag;
}


int main() {
    int T; cin >> T; while (T--) {
        int n, m; cin >> n >> m;
        vector<Edge> edges(m);
        vector<int> dis(n, INF);
        
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }

        if (BellmanFord(n, edges, dis))
            cout << "possible\n";
        else
            cout << "not possible\n";
    }
}
