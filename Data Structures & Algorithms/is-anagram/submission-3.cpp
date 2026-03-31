class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map< char , int>map;
        if (s.length()!= t.length()) return false;

        for (int i=0; i<s.length(); i++){
              map[s[i]] += 1;
        }
        for (int i=0; i<t.length(); i++){
            if (map.find(t[i]) == map.end() || map[t[i]] == 0){
                return false;
            }else{
                map[t[i]] -= 1;
            }
            }
            return true;

        }
};
