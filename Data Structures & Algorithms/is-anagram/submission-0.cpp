class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        for(int i=0; i<t.length() ; i++){
            size_t pos = s.find(t[i]);
            if (pos == string::npos){
                return false;
            }
            else{
                s.erase(pos, 1);
            }
        }
        return s.length() == 0;
    }
};
