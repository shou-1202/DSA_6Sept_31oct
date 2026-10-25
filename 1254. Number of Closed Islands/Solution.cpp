class Solution {
public:
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j){
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
           return false;
        }

// 2. Water check: If it hits water, it's safely closed on this side!
        if (grid[i][j] == 1) {
           return true;
        }

// 3. Visited check: If we already explored this land cell, it's safe. 
        if (vis[i][j] == 1) {
           return true; 
        }

        vis[i][j] = 1;
        bool right = false, left = false, up = false, down = false;
        if(grid[i][j] == 0){
            right = dfs(grid, vis, i, j+1);
            left = dfs(grid, vis, i, j-1);
            up = dfs(grid, vis, i-1, j);
            down = dfs(grid, vis, i+1, j);

            if(right && left && up && down)return true;
        }

        return false;
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 0 && grid[i][j] == 0){
                    if(dfs(grid, vis, i, j)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};