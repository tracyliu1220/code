class Solution {
public:
    int dp[105];
    int UNMARKED = -1;
    
    int solve(int n, vector<int>& nums) {
        // 已紀錄
        if (dp[n] != UNMARKED) return dp[n];
        
        // 邊界條件
        if (n == 0)
            return dp[0] = nums[0];
        if (n == 1)
            return dp[1] = max(nums[0], nums[1]);

        // 轉移
        return dp[n] = max(solve(n - 1, nums), solve(n - 2, nums) + nums[n]);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();

        // 邊界條件
        if (!n) return 0;
        
        // 將 dp 全部都初始化為 UNMARKED
        memset(dp, UNMARKED, sizeof(dp));
        
        return solve(n - 1, nums);
    }
};
