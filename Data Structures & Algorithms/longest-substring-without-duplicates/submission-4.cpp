class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char>sp;
          int x=0;
        for (int i=0; i<s.length(); i++){
          
           
               while (sp.count(s[i])){
                sp.erase(s[x]);
                x++;
               }
            
            sp.insert(s[i]);
             ans = max(ans, i-x+1);
        }

        return ans;
    }
};
