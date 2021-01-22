class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build the Graph and count the indegree
        vector<vector<int>> G(numCourses);
        vector<int> indeg(numCourses);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            G[u].push_back(v);
            indeg[v]++;
        }
        
        int cnt = 0;
        queue<int> que;
        
        // find the leaf (whose indegree == 0)
        for (int i = 0; i < numCourses; i++) {
            if (!indeg[i]) que.push(i);
        }
        
        while (que.size()) {
            int cur = que.front(); que.pop();
            cnt++;
            for (int i = 0; i < G[cur].size(); i++) {
                int nxt = G[cur][i];
                indeg[nxt]--;
                if (indeg[nxt] == 0) que.push(nxt);
            }
        }
        
        if (cnt == numCourses) return true;
        return false;
    }
};
