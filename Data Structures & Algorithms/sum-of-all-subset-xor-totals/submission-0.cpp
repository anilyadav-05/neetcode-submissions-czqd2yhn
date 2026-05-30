class Solution {
public:
     void sum(vector<int>& nums , vector<int>& subset,int& ans, int i){
        int sums = 0;
        if(i == nums.size()){
           for(int k : subset){
            sums = sums ^ k;
           }
           ans+=sums;
           return;
        }

        subset.push_back(nums[i]);
        sum( nums ,subset,  ans , i+1 );
        subset.pop_back();
        sum( nums ,subset,  ans , i+1 );
     }

    int subsetXORSum(vector<int>& nums) {
        vector<int>subset;
        int ans = 0;
         sum(nums ,subset,  ans , 0 );

         return ans;
    }
};