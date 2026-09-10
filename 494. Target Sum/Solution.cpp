class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int x : nums) totalSum += x;

        // FIX: Prevent out-of-bounds crash if target is impossible to reach
        if(abs(target) > totalSum) return 0;

        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, 0));

        // Base case: initialize for i = 0
        dp[0][nums[0] + totalSum] += 1;
        dp[0][-nums[0] + totalSum] += 1;

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= 2 * totalSum; j++){
                int plus = 0;
                int minus = 0;

                if (j - nums[i] >= 0) {
                    plus = dp[i-1][j - nums[i]];
                }
                if (j + nums[i] <= 2 * totalSum) {
                    minus = dp[i-1][j + nums[i]];
                }

                dp[i][j] = plus + minus;
            }
        }

        return dp[n-1][target + totalSum];
    }
};