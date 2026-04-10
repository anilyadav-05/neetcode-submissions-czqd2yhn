class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_set<int>s;
     int n = nums.size();
     int ans=0;
    
     
     for (int i=0; i<n ; i++){
        s.insert(nums[i]);
     }

     for(int i=0; i<n; i++){
        int c = 0;
         int x = nums[i];
        if (s.find(x-1) == s.end()){
            bool flag = false;
            while (flag == false){
                if (s.find(x) != s.end()){
                    x+=1;
                    c+=1;
                }else {
                    flag = true;
                }

            }
            ans = max(ans,c);

        }
     }
 return ans;

    }
};
