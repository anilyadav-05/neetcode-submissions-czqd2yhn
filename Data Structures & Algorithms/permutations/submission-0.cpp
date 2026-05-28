class Solution {
public:
    void Permutations(vector<int>& nums, int i ,vector<vector<int>>& ans ){
        if(i == nums.size()) {
            ans.push_back({nums});
            return;
        }
        for(int idx = i; idx<nums.size(); idx++){

            swap(nums[i],nums[idx]);

           Permutations(nums , i+1 , ans );

            swap(nums[i],nums[idx]);
            
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
      
      
        Permutations(nums , 0 , ans );
         return ans;
    }
};
