class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int j = 0;int i = 0;
        unordered_map<int, int>s;
        int maxCount = 0, count = 0;
        while(j<fruits.size() && i<fruits.size()){
            s[fruits[i]]++;
            count++;
            i++;
            while(s.size()>2){
                s[fruits[j]]--;
                if(s[fruits[j]] == 0){
                    s.erase(fruits[j]);
                }
                count--;
                j++;
            }
            maxCount = max(count, maxCount);
            
        }
        return maxCount;
    }
};