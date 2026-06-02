class Solution {
public:
     
    void combination(vector<int>& nums, vector<vector<int>>& ans , vector<int>& sub , int sum , int target, int idx){
          
          if(sum == target){     
                   ans.push_back(sub);     
                    return;
                }
                if(sum > target) return;

        for(int i=idx; i<nums.size(); i++){
           if(i > idx && nums[i] == nums[i-1]) continue;
                sub.push_back(nums[i]);
                sum+=nums[i]; 

                combination( nums, ans, sub, sum, target, i+1);

                sum-=nums[i];   // backtracking
                sub.pop_back();                    
                
            }
            
        }  
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
            vector<vector<int>>ans;
            vector<int> sub;
            combination(nums, ans , sub , 0, target , 0);

            return ans;
    }
};