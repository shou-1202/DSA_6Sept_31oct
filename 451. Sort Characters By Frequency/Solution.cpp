class Solution {
public:
    string frequencySort(string s) {
        string ans = "";

        unordered_map<char, int>m;
        for(int i = 0; i<s.length(); i++){
            m[s[i]]++;
        }

        priority_queue<pair<int, int>>pq;
        for(auto it: m){
            pq.push({it.second, it.first});
        }

        while(!pq.empty()){ 
            int freq = pq.top().first;
            while(freq!=0){
                ans += pq.top().second;
                freq--;
            }
            pq.pop();
        }

        return ans;
    }
};