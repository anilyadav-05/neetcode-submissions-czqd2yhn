class Solution {
public:

  unordered_set<string> dict;

    void helper(string s , vector<string>& wordDict ,vector<string>& ans , string sentence , int idx){
        if(idx == s.length()) {
            ans.push_back(sentence.substr(0, sentence.length()-1));
            return;
        }
           
        for(int i=idx; i<s.length(); i++){
            string temp = s.substr(idx, i-idx+1);        
                                          
            if(dict.count(temp)) {
                 temp+=" "; 
                helper( s ,wordDict , ans , sentence + temp, i+1 ); // recursion
                        
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        string sentence = "";
        
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        helper( s ,wordDict , ans , sentence , 0 );

         return ans;
    }
};