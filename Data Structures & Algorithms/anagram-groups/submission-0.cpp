class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>>ans;
       
      unordered_map<string, vector<string>>mp;

      int n = strs.size();

      for(int i =0; i<n; i++){
        
        string sign = strs[i];
        sort(sign.begin(), sign.end());

       
            mp[sign].push_back(strs[i]);
        
      }

      for(auto& pair : mp ){
        ans.push_back(pair.second);
      }
      return ans;
    }
};
