class Solution {
public:
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
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        pa.clear(); pa.resize(n);
        for (int i = 0; i < n; i++)
            pa[i] = i;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (isConnected[i][j])
                    merge(i, j);
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (pa[i] == i)
                ans++;
        
        return ans;
    }
};
