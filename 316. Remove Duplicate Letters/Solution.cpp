class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        unordered_map<char, int>m;

        for(int i = 0; i<s.length(); i++){
            m[s[i]]++;
        }
        vector<bool>vis(26, false);
        int i = 0;
        while(i<s.length()){
            m[s[i]]--;
            int idx = s[i] - 'a';
            if(vis[idx]){
                i++;
                continue;
            }
            while(!st.empty() && s[i] < st.top() && m[st.top()] > 0){
                vis[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i] - 'a'] = true;
            i++;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};