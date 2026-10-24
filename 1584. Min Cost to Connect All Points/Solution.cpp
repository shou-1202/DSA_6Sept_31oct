class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>>adj[n];

        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;

        vector<int>vis(n, 0);

        pq.push({0, 0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int wt = it.first;
            pq.pop();

            if(vis[node])continue;
            vis[node]=1;sum+=wt;

            for(auto i : adj[node]){
                int v = i.first;
                int edgeW = i.second;

                if(!vis[v]){
                    pq.push({edgeW, v});
                }
            }
        }

        return sum;

        

    }
};