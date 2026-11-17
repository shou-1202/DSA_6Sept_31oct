class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count frequency of each task ('A' to 'Z')
        vector<int> freq(26, 0);
        for (char t : tasks) {
            freq[t - 'A']++;
        }

        // Max-heap to always pick the tasks with the highest remaining frequency
        priority_queue<int> pq;
        for (int count : freq) {
            if (count > 0) {
                pq.push(count);
            }
        }

        int time = 0;

        // Process tasks in cycles of length (n + 1)
        while (!pq.empty()) {
            vector<int> temp;
            int cycleTasks = 0;

            // Execute up to (n + 1) distinct tasks in one cycle
            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    int currFreq = pq.top();
                    pq.pop();
                    
                    if (currFreq - 1 > 0) {
                        temp.push_back(currFreq - 1);
                    }
                    cycleTasks++;
                }
            }

            // Push remaining task frequencies back into the heap for the next cycle
            for (int rem : temp) {
                pq.push(rem);
            }

            // If pq is empty, all tasks are done (no trailing idle slots needed).
            // Otherwise, the full (n + 1) window (including any idle slots) was used.
            if (pq.empty()) {
                time += cycleTasks;
            } else {
                time += (n + 1);
            }
        }

        return time;
    }
};