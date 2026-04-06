class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>answer;
       vector<int>ans (2000 , 0);
       for (int i = 0; i<nums.size(); i++){
        ans[nums[i] + 1000]++;

       } while (answer.size()<k){
        int m=0;
        int x;
       for (int i=0; i<=2000; i++){
        if (m<ans[i]){
            m=ans[i];
            x=i;
        }
          
        
       } answer.push_back(x-1000);
       ans[x]=0;
       
       
       }

return answer;

    }
};
