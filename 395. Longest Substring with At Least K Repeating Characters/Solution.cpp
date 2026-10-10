class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        
        int i = 0;
        int ans = INT_MIN;
        while(i<n){
            vector<int>freq(26, 0);
            int j = i;
            while(j<n){
                int idx = s[j] - 'a';
                freq[idx] += 1;

                bool isValid = true;
                for (int c = 0; c < 26; c++) {
                    if (freq[c] > 0 && freq[c] < k) {
                        isValid = false;
                        break;
                    }
                }

                if(isValid){
                    ans = max(ans, j-i+1);
                }
                j++;
            }
            i++;
        }
        if(ans == INT_MIN)return 0;
        return ans;
    }
};