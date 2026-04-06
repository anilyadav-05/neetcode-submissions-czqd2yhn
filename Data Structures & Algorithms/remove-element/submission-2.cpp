class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans =0;
        int y=nums.size()-1;
        int i=0;
        while (i<=y){
           if (nums[i] == val){
                if(nums[y] != val){
                    swap(nums[i],nums[y]);
                    ans++;
                    i++;
                    y--;} else{
            y--;}
        }else {
            ans++;
            i++;
            continue;
        }}
        return ans;
    }
};