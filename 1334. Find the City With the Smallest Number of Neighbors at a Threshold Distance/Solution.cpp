class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n, vector<int>(n, 1e9));

        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v =  edges[i][1];
            int wt = edges[i][2];

            adj[u][v] = wt;
            adj[v][u] = wt;
        }

        for(int i = 0; i<n; i++){
            adj[i][i] = 0;
        }

        vector<int>ans(n, 0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    adj[j][k] = min(adj[j][k], adj[j][i]+adj[i][k]);
                }
            }
        }

        int cntMax = n ;
        int city = -1;
        for(int i = 0; i<n;i++){
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(adj[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cntMax >= cnt){
                cntMax = cnt;
                city = i;
            }
        }

        return city;
        


    }
};