class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pri[nums.size()];
        int suf[nums.size()];
        vector<int>ans(nums.size());
         
         pri[0]= nums[0];
         suf[nums.size()-1]= nums[nums.size()-1];
        for (int i = 1; i<nums.size(); i++){
            pri[i] = nums[i]*pri[i-1];
           
        }
        for (int i =nums.size()-2 ; i>=0; i--){
            
            suf[i]= nums[i]*suf[i+1];
        }
         for (int i = 0; i<nums.size(); i++){
           if (i==0){
            ans[i]= suf[1];
           }else if(i== nums.size()-1){
           ans[i]= pri[nums.size()-2] ;
           }else{
            ans[i]= pri[i-1]*suf[i+1];
           }
         }
         return ans;
    }
};
