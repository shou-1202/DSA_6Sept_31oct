class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        int n = words.size();
        
        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();
            
            // 1. Determine how many words fit on the current line
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }
            
            int numWords = j - i;
            int numSpaces = maxWidth - lineLength;
            string line = words[i];
            
            // 2. Format the last line or a line with only one word (Left Justified)
            if (numWords == 1 || j == n) {
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                line.append(maxWidth - line.length(), ' '); // Pad right with spaces
            } 
            // 3. Format standard lines (Fully Justified)
            else {
                int baseSpaces = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);
                
                for (int k = i + 1; k < j; k++) {
                    // Apply base spaces
                    line.append(baseSpaces, ' ');
                    // Distribute extra spaces strictly left-to-right
                    if (extraSpaces > 0) {
                        line.push_back(' ');
                        extraSpaces--;
                    }
                    line += words[k];
                }
            }
            
            ans.push_back(line);
            i = j; // Move to the next set of words
        }
        
        return ans;
    }
};