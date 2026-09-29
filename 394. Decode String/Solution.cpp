class Solution {
public:
    string decodeString(string s) {
        vector<int>nums;
        stack<string>st;

        int i = 0, num = 0;
        string a = "";
        while(i<s.length()){
            if(isdigit(s[i])){
                num = num*10 + (s[i] - '0');
            }
            else if(s[i] == '['){
                nums.push_back(num);
                num = 0;
                st.push(a);
                a = "";
            }
            else if(isalpha(s[i])){
                a += s[i];
            }
            else if(s[i] == ']'){
               int n = nums.back(); nums.pop_back();
               string prev = st.top();st.pop();

               for(int j = 0; j<n; j++){
                prev += a;
               }

               a = prev;
            }
            i++;
        }
        return a;
    }
};