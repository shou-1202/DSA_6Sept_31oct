class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        vector<int>freq(26, 0);
        int n = s.length();

        unordered_map<string, int>m;
        int i = 0, j = i, ans = 0;
        while(i<s.length() && j<s.length()){
            if(freq[s[j]-'a'] == 0){
                maxLetters--;
            }
            freq[s[j] - 'a']++;

            if(j-i+1 > minSize){
                freq[s[i] - 'a']--;
                if(freq[s[i] - 'a'] == 0){
                    maxLetters++;
                }
                i++;
            }

            if(j-i+1 == minSize && maxLetters >= 0){
                string str = s.substr(i, (j-i+1));
                ans = max(ans, ++m[str]);
            }
            j++;
        }
        return ans;

    }
};