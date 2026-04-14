class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int i=1;
        int j=0;
        int M = nums[0];
        int m = 1000000001;
        int x;
        
        int n = nums.size();

        for( x = 1; x<n ; x++){
            if (nums[x] == M){
                i++;
                continue;
            }else {
                m= nums[x];
                j++;
                break;
            }

        }
        x++;
        while ( x < n){
            if(nums[x] == M){
                i++;
            }else if ( nums[x] == m){
                j++;
            }else {
                i--;
                j--;
            }

            if (i <0){
                M = nums[x];
                i=(-i);
            }else if(j < 0 ){
                m = nums[x];
                j=(-j);
            }
            x++;
        }

    i = 0;
    j=0;
     for (int k : nums){
        if ( k == M){
            i++;
        }else if (k == m){
            j++;
        }
            
        
     }
     if ( i > n/3){
        ans.push_back(M);
     }
       if ( j > n/3){
        ans.push_back(m);
     }

return ans;
    }
};