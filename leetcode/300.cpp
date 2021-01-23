class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int INF = 1e9+7;
        vector<int> LIS(a.size(), INF);
        for (int x:a)*lower_bound(LIS.begin(), LIS.end(), x) = x;
        return lower_bound(LIS.begin(), LIS.end(), INF) - LIS.begin();
    }
};
