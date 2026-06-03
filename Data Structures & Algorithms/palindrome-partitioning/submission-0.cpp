class Solution {
public:
 
    bool palindrome(string k){
        int i = 0; 
        int j = k.length()-1;
        while(i<j){
            if(k[i] != k[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    
    void helper(vector<vector<string>>&ans , vector<string>temp , string s , int idx){
       if(idx == s.length()) {
        ans.push_back(temp);
        return;
       }
       string k = "";
       for(int i = idx; i<s.length(); i++){
        k = k+s[i];
        if(palindrome(k)){
            temp.push_back(k);
            helper(ans , temp, s , i+1);
            temp.pop_back();
        }

       }
       
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        
        helper(ans , temp, s , 0);

        return ans;
    }
};
