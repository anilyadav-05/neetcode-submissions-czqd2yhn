class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
   unordered_map<int, int> map; 


    for (int i = 0; i < nums.size(); i++) {
        int c = target - nums[i];

        if (map.find(c) != map.end()) {
            ans.push_back(min(map[c], i));
            ans.push_back(max(map[c], i));
        }

        map[nums[i]] = i;
    }

    return ans;
    }
};
