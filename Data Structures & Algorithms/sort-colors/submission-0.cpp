class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x=0,y = 0;
        int z= nums.size()-1;

        while (y<=z){
            if (nums[y]==0){
                swap (nums[y], nums[x]);
                y++;
                x++;
            }else if (nums[y]==1){
                y++;
            }else{
                swap (nums[y], nums[z]);
                
                z--;
            }
        }
    }
};