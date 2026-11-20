class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
       sort(nums.begin(), nums.end()); 
       int n = nums.size();
       int sz = nums[n-1];
       vector<int>dp(sz+2, 0);

       int ans = INT_MIN;
       for(int i = 0; i<n; i++){
          dp[nums[i]+1] = dp[nums[i]]+1;
          dp[nums[i]] = dp[nums[i]-1]+1;

          ans = max(ans, max(dp[nums[i]], dp[nums[i]+1]));
       }

       return ans;
    }
};