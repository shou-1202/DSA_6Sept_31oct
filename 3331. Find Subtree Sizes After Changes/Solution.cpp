class Solution {
public:
    int dfs(vector<vector<int>>& newAdj, vector<int>& ans, int root){
        for(int child: newAdj[root]){
            ans[root] += dfs(newAdj, ans, child);
        }
        return ans[root];
    }
    void helper(vector<vector<int>>& adj, string &s, int root, vector<int>& lastseen, vector<int>& newParent){
        int prev = lastseen[s[root]-'a'];
        if(prev != -1){
            newParent[root] = prev;
        }
        lastseen[s[root]-'a'] = root;
        for(int i = 0; i<adj[root].size(); i++){
            helper(adj, s, adj[root][i], lastseen, newParent);
        }
        lastseen[s[root]-'a'] = prev;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int>ans(n, 1);
        vector<vector<int>>adj(n);
        vector<vector<int>>newAdj(n);
        vector<int>newParent = parent;
        vector<int>lastseen(26, -1);
        for(int i = 1; i<n; i++){
            adj[parent[i]].push_back(i);
        }

        helper(adj, s, 0, lastseen, newParent);

        for(int i = 1; i<n; i++){
            newAdj[newParent[i]].push_back(i);
        }

        dfs(newAdj, ans, 0);
        return ans;

    }
};