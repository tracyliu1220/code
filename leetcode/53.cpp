class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin(), 0);
        vector<int> dp(n+1, 0);
        
        int ans = a[1];
        
        for (int i=1; i<=n; i++){
            dp[i] = max(dp[i-1], 0) + a[i];
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
