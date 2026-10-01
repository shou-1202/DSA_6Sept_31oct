class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        // Priority queue storing {sum, {index_in_nums1, index_in_nums2}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        // 1. Initialize: Pair the first k elements of nums1 with the first element of nums2
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }
        
        // 2. Extract the smallest pairs k times
        while (k > 0 && !pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int i = it.second.first;
            int j = it.second.second;
            
            ans.push_back({nums1[i], nums2[j]});
            k--; // We successfully found one of our k pairs
            
            // 3. Push the next possible pair from the SAME row (incrementing j)
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }
        
        return ans;
    }
};