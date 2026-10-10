class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -1e4;

        int i = 0;
        int n = nums.size();
        int sum = 0;
        for(int j = 0; j<k; j++){
            sum += nums[j];
        }
        ans = (double)sum/k;
        i+=1;
        while(i<=(n-k)){
            int sub = nums[i-1];
            int add = nums[i+k-1];
            sum -= sub;
            sum+= add;
            ans = max((double)sum/k, ans);
            i++;
        }
        return ans;
    }
};