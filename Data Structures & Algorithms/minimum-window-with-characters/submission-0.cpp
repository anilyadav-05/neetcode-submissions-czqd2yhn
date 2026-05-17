class Solution {
public:
    string minWindow(string s, string t) {
      
        vector<int> m(128, 0);  // frequency map for t
        vector<int> n(128, 0);  // frequency map for window
        
        int p = t.length();
        int q = s.length();
        
        // Fill t's frequency map
        for(int i = 0; i < p; i++){
            m[t[i]]++;
        }
        
        int i = 0, j = 0;
        int need = p;      // total chars needed
        int formed = 0;    // total chars satisfied
        int minLen = INT_MAX;
        string ans = "";
        
        while(j < q){
            char c = s[j];
            n[c]++;
            
            // If this char is needed and count is now satisfied
            if(m[c] > 0 && n[c] <= m[c]){
                formed++;
            }
            
            // Try to shrink from left
            while(formed == need){
                // Update answer
                if(j - i + 1 < minLen){
                    minLen = j - i + 1;
                    ans = s.substr(i, minLen);
                }
                
                // Remove s[i] from window
                char left = s[i];
                n[left]--;
                if(m[left] > 0 && n[left] < m[left]){
                    formed--;
                }
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};

