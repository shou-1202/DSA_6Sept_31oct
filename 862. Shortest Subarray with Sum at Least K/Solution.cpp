#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Use long long for prefix sums to avoid integer overflow
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = INT_MAX;
        deque<int> dq; // Stores indices of the prefix array

        for (int i = 0; i <= n; i++) {
            // 1. Check if we found a valid subarray
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front(); // We can pop it because any future 'i' will yield a longer subarray
            }

            // 2. Maintain monotonic increasing order in the deque
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back(); 
            }

            // Add current index to deque
            dq.push_back(i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};