class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == 1)return arr;
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;

        vector<int>ans;
        int n = arr.size();
        int i;
        for(i = 0; i<n; i++){
            int dif = abs(arr[i] - x);
            pq.push({dif, arr[i]});
        }
        for(int i = 0; i <k; i++){
           auto it = pq.top();
           pq.pop();
           ans.push_back(it.second);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};