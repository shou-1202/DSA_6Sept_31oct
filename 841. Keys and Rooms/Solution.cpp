class Solution {
public:
    void helper(int i, vector<vector<int>>& rooms, vector<int>& vis){
        vis[i] = 1;

        for(auto neigh: rooms[i]){
            if(!vis[neigh]){
                helper(neigh, rooms, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int>vis(n, 0);

        helper(0, rooms, vis);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};