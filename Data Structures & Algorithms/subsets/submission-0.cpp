class Solution {
public: 
    void subset(vector<int>& nums ,vector<vector<int>>& ans , vector<int>& sub, int i){
        if(i == nums.size()) {
            ans.push_back(sub);
            return ;}

            sub.push_back(nums[i]);
             subset(nums , ans , sub , i+1);
             sub.pop_back();
             subset(nums , ans , sub , i+1);

         

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub = {};
        int i = 0;
        subset(nums , ans , sub , i);

        return ans;
    }
};
