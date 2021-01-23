class Solution {
public:
    int dp[105];
    int rob(vector<int>& nums) {
        int n = nums.size();

        // 邊界條件
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // 轉移
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        // 答案
        return dp[n - 1];
    }
};
