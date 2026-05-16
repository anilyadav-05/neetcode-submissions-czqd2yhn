class Solution {
public:
    bool checkInclusion(string s1, string s2) {

       if (s1.length() > s2.length()) return false;
      vector<int>x(26 , 0);
       vector<int>y(26 , 0);
       int k=0;
        
        int window = s1.length();

        for(int i =0; i<window; i++ ){
            x[s1[i] - 'a']++;
            y[s2[i] - 'a']++;
        }
        if (x == y) return true;

        for (int i=window; i<s2.length(); i++){
            y[s2[k] - 'a']--;
            y[s2[i] - 'a']++;
            k++;
             if (x == y) return true;

        }
        return false;
    }
};
