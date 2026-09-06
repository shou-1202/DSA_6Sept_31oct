class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n);
        deque<int>dq;
        int maxSum = nums[0];

        for(int i = 0; i<n; i++){
            if(!dq.empty() && (i-dq.front()) >k){
                dq.pop_front();
            }

            dp[i] = nums[i];
            if(!dq.empty()){
                dp[i] = max(dp[i], nums[i]+dp[dq.front()]);
            }

            maxSum = max(maxSum, dp[i]);

            while(!dq.empty() && dp[dq.back()] <= dp[i]){
                dq.pop_back();
            }

            if(dp[i]>0){
                dq.push_back(i);
            }
        }
        return maxSum;
    }
};