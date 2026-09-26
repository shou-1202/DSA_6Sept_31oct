class Solution {
public:
    int helper(int n, int m, int maxMove, int i, int j,vector<vector<vector<int>>>& dp){
        if((i==m || j == n || i<0 || j<0) && maxMove>=0)return 1;
        if(maxMove<0)return 0;
        if(dp[i][j][maxMove]!=-1)return dp[i][j][maxMove];
        

        long long left = 0, right = 0, up = 0, down = 0;

        left += helper(n, m, maxMove-1, i, j-1, dp);
        right += helper(n, m, maxMove-1, i, j+1, dp);
        up += helper(n, m, maxMove-1, i-1, j, dp);
        down += helper(n, m, maxMove-1, i+1, j, dp);

        int modulo = 1e9+7;
        return dp[i][j][maxMove] = (left+right+up+down)%modulo;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return helper(n, m, maxMove, startRow, startColumn, dp);
    }
};