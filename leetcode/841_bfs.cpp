class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& G) {
        if (G.empty()) return true;
        vector<bool> vis(G.size());

        // BFS
        queue<int> que;
        que.push(0);
        vis[0] = true;

        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : G[u]) {
                if (!vis[v]) {
                    que.push(v);
                    vis[v] = true;
                }
            }
        }

        return *min_element(vis.begin(), vis.end());
    }
};
