class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int , pair<int, int>>,
                       vector<pair<int , pair<int, int>>>,
                       greater<pair<int , pair<int, int>>>>pq;
        pq.push({0, {0, 0}});

        vector<vector<int>>vis(n, vector<int>(m, 1e9));
        vis[0][0] = 0;
        int dc[4] = {-1, 0, 1, 0};
        int dr[4] = {0, -1, 0, 1};

        while(!pq.empty()){
            auto it = pq.top();
            int i = it.second.first;
            int j = it.second.second;
            int effort = it.first;
            pq.pop();
            vis[i][j] =  effort;
            if(i == n-1 && j == m-1){
                return effort;
            }

            for(int k = 0; k<4; k++){
                int nr = i+ dr[k];
                int nc = j + dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int cost = abs(heights[i][j] - heights[nr][nc]);
                    int newEffort = max(effort, cost);
                    if(newEffort < vis[nr][nc]){
                        vis[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};