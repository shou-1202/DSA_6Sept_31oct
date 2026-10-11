class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length(), len2 = s2.length();
        
        // History arrays to track state at the end of each s1 block
        vector<int> countHistory; 
        vector<int> indexHistory; 
        
        int count1 = 0, count2 = 0, j = 0;
        
        while (count1 < n1) {
            // 1. Process one full block of s1
            for (int i = 0; i < len1; ++i) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == len2) {
                        count2++;
                        j = 0;
                    }
                }
            }
            count1++;
            
            // 2. Record the state
            countHistory.push_back(count2);
            indexHistory.push_back(j);
            
            // 3. Cycle Detection
            // Check if we have ever ended an s1 block on this exact 'j' before
            for (int k = 0; k < count1 - 1; ++k) {
                if (indexHistory[k] == j) {
                    // We found a cycle!
                    int cycleLen = count1 - 1 - k; // How many s1 blocks make up the cycle
                    int cycleMatches = count2 - countHistory[k]; // How many matches occur per cycle
                    
                    int remainingBlocks = n1 - count1;
                    int skipCycles = remainingBlocks / cycleLen;
                    
                    // Fast-forward the matches
                    int totalMatches = count2 + (skipCycles * cycleMatches);
                    
                    // Add the matches for the tiny remainder of blocks that don't make a full cycle
                    int leftOverBlocks = remainingBlocks % cycleLen;
                    int leftOverMatches = countHistory[k + leftOverBlocks] - countHistory[k];
                    
                    return (totalMatches + leftOverMatches) / n2;
                }
            }
        }
        
        // If no cycle was found (n1 was very small), just return the simulated count
        return count2 / n2;
    }
};