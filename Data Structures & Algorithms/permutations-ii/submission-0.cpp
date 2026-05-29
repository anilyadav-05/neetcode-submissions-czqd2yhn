class Solution {
public:
    void Permutations(vector<int>& nums, int i ,vector<vector<int>>& ans ){
        if(i == nums.size()) {
            ans.push_back({nums});
            return;
        }
        unordered_set<int> seen;
        for(int idx = i; idx<nums.size(); idx++){
            if (seen.count(nums[idx])) continue; // skip duplicate VALUE at this position
        seen.insert(nums[idx]);


            swap(nums[i],nums[idx]);

           Permutations(nums , i+1 , ans );

            swap(nums[i],nums[idx]);
            
        }
        
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
       
       sort(nums.begin(), nums.end());
      
        Permutations(nums , 0 , ans );
         return ans;
    }
};