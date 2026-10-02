class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1)return -1;
        vector<vector<int>>vis(n , vector<int>(m, 0));
        queue<pair<int, int>>q;
        q.push({0,0});
        vis[0][0] = 1;
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        int pathlength = 1;
        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i<size; i++){
                auto [r, c] = q.front();
                q.pop();

                if(r == n-1 && c ==m-1){
                    return pathlength;
                }

                for(auto dir: directions){
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && vis[nr][nc] == 0 && grid[nr][nc] == 0){
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
            pathlength++;


        }
        return -1;
    }
};