class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        a.insert(0, "$");
        b.insert(0, "$");
        
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        dp[0][0] = 0;
        for (int i=1; i<=n; i++) dp[i][0] = 0;
        for (int j=1; j<=m; j++) dp[0][j] = 0;
        
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
};
