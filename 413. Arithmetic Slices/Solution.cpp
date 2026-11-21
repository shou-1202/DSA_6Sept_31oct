class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
       if(nums.size()<3)return 0;

       int i = 0, j = 1, ans = 0;
       while(i<nums.size()-2){
        int diff = nums[i+1]-nums[i];
        while(j < nums.size() && nums[j]-nums[j-1] == diff){
            j++;
        }
        int len = j-i;
        len -= 2;
        for(int i = 1; i<=len; i++){
            ans = ans + (len-i+1);
        }
        i = j-1;
       } 
       return ans;
    }
};