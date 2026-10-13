class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i<nums.size();i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, j = n-1;

        long long ans = 0;
        while(i<j){
            long long sq = nums[j] * nums[j];
            ans += sq;
            sq = nums[i]*nums[i];
            ans-=sq;

            i++;j--;
        }
        if(i==j){
            long long sq = nums[i]*nums[i];
            ans+=sq;
        }
        return ans;

    }
};