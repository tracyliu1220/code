class Solution {
public:
    int coinChange(vector<int>& a, int W) {
        const int INF = 1e9 + 7;
        vector<int> dp(W+1, INF);
        dp[0] = 0;
        for (int x:a){
            for (int i=x; i<=W; i++){
                dp[i] = min(dp[i], dp[i-x] + 1);
            }
        }
        
        if (dp[W] == INF) return -1;
        return dp[W];
    }
};
