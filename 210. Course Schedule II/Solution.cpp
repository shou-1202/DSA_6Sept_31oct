class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses, 0);
        vector<int>adj[numCourses];
        for(int i = 0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i = 0; i<prerequisites.size(); i++){
            int a = prerequisites[i][1];
            indegree[a] += 1;
        }
        queue<int>q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int n = q.front();q.pop();
            topo.push_back(n);
            for(auto neigh: adj[n]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        reverse(topo.begin(), topo.end());
        if(topo.size()<numCourses){
            topo.clear();
            return topo;
        }
        return topo;
    }
};