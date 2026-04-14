class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans =0;
        
        

        for (int i = 0; i<nums.size() ; i++){
            if (nums[i] == k) ans++;
            int j = i+1;
            int sum = nums[j];
            while (j<nums.size()) {

            if ( (k - nums[i]) == sum ) {
                ans++;} 
                j++;
                    sum += nums[j];
                


            }

        }
        return ans;
    }
};