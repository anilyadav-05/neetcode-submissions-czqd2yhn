class Solution {
public: 
    void subset(vector<int>& nums ,vector<vector<int>>& ans , vector<int>& sub, int i){
        if(i == nums.size()) {
            ans.push_back(sub);
            return ;}

            sub.push_back(nums[i]);
             subset(nums , ans , sub , i+1);
             sub.pop_back();
             int idx = i+1;
             while(idx<nums.size() && nums[idx-1] == nums[idx]){
                idx++;
             }
             subset(nums , ans , sub , idx);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>sub = {};
        int i = 0;
        subset(nums , ans , sub , i);

        return ans;
    }
};