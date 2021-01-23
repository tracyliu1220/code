class Solution {
public:
    int minDistance(string a, string b) {
        a.insert(0, "$");
        b.insert(0, "$");
        int n = a.size();
        int m = b.size();
        
        vector<vector<int>> dp(n, vector<int>(m, n+m));
        
        for (int i=0; i<n; i++) dp[i][0] = i;
        for (int i=0; i<m; i++) dp[0][i] = i;
        
        for (int i=1; i<n; i++){
            for (int j=1; j<m; j++){
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                if (a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
        
        return dp[n-1][m-1];
    }
};
