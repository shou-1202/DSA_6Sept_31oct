class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int>m;
        for(int i = 0; i<secret.length(); i++){
            m[secret[i]]++;
        }

        int bulls =0, cows = 0;
        for(int i = 0;i<secret.length(); i++){
            if(secret[i] == guess[i]){
                bulls++;
                m[secret[i]]--;
            }
        }
        for(int i = 0;i<secret.length(); i++){
            if(secret[i] != guess[i] && m.find(guess[i])!=m.end() && m[guess[i]] !=0){
                cows++;
                m[guess[i]]--;
            }
        }

        string b = to_string(bulls);
        string c = to_string(cows);

        string result = b+"A"+c+"B";

        return result;

    }
};