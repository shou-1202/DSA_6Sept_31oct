class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();

        vector<vector<vector<int>>>dp(sz+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i = 1; i<=sz; i++){
            int z = 0, o = 0;
            for(int p = 0; p<strs[i-1].size(); p++){
                if(strs[i-1][p] == '0'){
                    z++;
                }
                else{
                    o++;
                }
            }
            for(int j = 0; j<=m; j++){
                for(int k = 0; k<=n; k++){
                    int pick = 0, notPick = 0;
                    
                    if(j>=z && k>=o)pick = 1+dp[i-1][j-z][k-o];
                    notPick = dp[i-1][j][k];

                    dp[i][j][k] = max(pick, notPick);
                }
            }
        }

        return dp[sz][m][n];
    }
};