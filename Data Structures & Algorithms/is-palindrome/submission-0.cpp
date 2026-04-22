class Solution {
public:
    bool isPalindrome(string s) {
        
      
        int n= s.length()-1;
        int i=0;

        while (i<n){
            if ( !isalnum(s[i]) ){
                i++;
            }else if ( !isalnum(s[n])){
                n--;
            }else {
               if( tolower(s[i]) != tolower(s[n])){
                
                return false;
               }else {
                n--;
                i++;
               }
            }
        }

        

        return true;

    
    }
};
