class Solution {
public:

    void helper(vector<vector<int>>&ans, vector<int>&subans, int n, int k , int idx){

        if(subans.size()==k){
            ans.push_back(subans);
            return;
        }
        

        for(int i=idx; i<=n; i++){
            subans.push_back(i);
            helper(ans, subans, n, k, i+1);   // recursion
            subans.pop_back();                  // backtraking

        }

    }



    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>subans;

        helper(ans , subans, n , k , 1);

return ans;
    }
};