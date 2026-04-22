class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int i = 0;
        int n= nums.size()-1;

        while(i<n){
            if ((nums[i] + nums[n]) > target){
                n--;
            } else if((nums[i] + nums[n]) < target){
                i++;
                
            }else if ((nums[i] + nums[n]) == target){
                ans.push_back(i+1);
                ans.push_back(n+1);
                break;
            }
        }
        return ans;
    }
};
