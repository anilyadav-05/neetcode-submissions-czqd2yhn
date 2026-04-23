class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
               string result = "";
        int i = 0; // Pointer for word1
        int j = 0; // Pointer for word2
        
        // Loop while either string still has characters left
        while (i < word1.length() || j < word2.length()) {
            // If word1 has characters left, append and increment
            if (i < word1.length()) {
                result += word1[i];
                i++;
            }
            // If word2 has characters left, append and increment
            if (j < word2.length()) {
                result += word2[j];
                j++;
            }
        }
        
        return result;
        }
    
};