class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        if(arr.size() == 2)return arr;
        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>>pq;

        for(int i = 0; i<arr.size()-1; i++){
            for(int j = i+1; j<arr.size(); j++){
                double a = (double)arr[i]/(double)arr[j];
                pq.push({a, {i, j}});
            }
        }

        for(int i = 0;i<k-1;i++){
            pq.pop();
        }
        vector<int>ans;
        auto it = pq.top();
        ans.push_back(arr[it.second.first]);
        ans.push_back(arr[it.second.second]);

        return ans;
    }
};