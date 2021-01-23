class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for (int i=0; i<=n; i++) dp[i] = i;
        for (int i=2; i*i<=n; i++){
            int p = i*i;
            for (int j=p; j<=n; j++){
                dp[j] = min(dp[j], dp[j-p]+1);
            }
        }
        
        return dp[n];
    }
};
