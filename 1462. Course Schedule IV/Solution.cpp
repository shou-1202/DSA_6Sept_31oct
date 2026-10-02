class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> adj[numCourses];

        for(int i = 0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }



        vector<int>indegree(numCourses, 0);
        for(int i = 0; i<numCourses; i++){
            for(int it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        unordered_set<int> prereqSets[numCourses];

while(!q.empty()){
    int u = q.front();
    q.pop();
    
    for(auto v: adj[u]){
        // 1. Add the direct parent
        prereqSets[v].insert(u);
        
        // 2. Add all ancestors (indirect parents) of u into v
        for(auto pre : prereqSets[u]){
            prereqSets[v].insert(pre);
        }
        
        indegree[v]--;
        if(indegree[v] == 0){
            q.push(v);
        }
    }
}
        int sz = queries.size();
        vector<bool>ans(sz, false);
        for(int i = 0; i<sz; i++){
            int a = queries[i][0];
            int b = queries[i][1];

            if(prereqSets[b].find(a) != prereqSets[b].end()){
                ans[i] = true;
            }
        }

        return ans;
    }
};