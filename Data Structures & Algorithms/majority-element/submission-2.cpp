class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n=1;
       int z=nums[0];
       for (int i=1; i<nums.size() ; i++){
        if (z == nums[i]){
            n++;
        }else {
            n--;
        }
        if (n<=0){
            z= nums[i];
            n=1;
        } 
        

       } return z;
    }
};