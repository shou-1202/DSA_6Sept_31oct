class Solution {
public:
    int helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, map<vector<int>, int>& m) {
        if(m[needs] != 0)return m[needs];

        int min_cost = 0;
        for (int i = 0; i < needs.size(); i++) {
            min_cost += needs[i] * price[i];
        }
        
        
        for (int i = 0; i < special.size(); i++) {
            bool isValid = true;
            for (int j = 0; j < needs.size(); j++) {
                if (needs[j] < special[i][j]) {
                    isValid = false;
                    break;
                }
            }
            
            
            if (isValid) {
                int n = needs.size();
                
               
                for (int k = 0; k < n; k++) {
                    needs[k] -= special[i][k];
                }
                
                
                int cost_with_offer = special[i][n] + helper(price, special, needs, m);
                min_cost = min(min_cost, cost_with_offer);
                
                
                for (int k = 0; k < n; k++) {
                    needs[k] += special[i][k];
                }
            }
        }
        
        return m[needs] = min_cost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>, int>m;
        helper(price, special, needs, m);
        return m[needs];
    }
};