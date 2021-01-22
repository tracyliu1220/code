class Solution {
public:
    void dfs(int u, vector<vector<int>> &G, vector<bool> &vis) {
        if (vis[u]) return;
        vis[u] = true;
        for (int v : G[u]) {
            dfs(v, G, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &G) {
        if (G.empty()) return true;
        vector<bool> vis(G.size());
        dfs(0, G, vis);
        return *min_element(vis.begin(), vis.end());
    }
};
