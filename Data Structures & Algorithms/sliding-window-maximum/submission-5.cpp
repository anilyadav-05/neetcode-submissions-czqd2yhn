class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
       deque<int>max;

       for(int i = 0; i<k; i++){
        if(max.empty())max.push_back(i);
        else {
            while(!max.empty() && nums[max.back()] <= nums[i]) max.pop_back();
            max.push_back(i);
        }
        }
        ans.push_back(nums[max.front()]);

        for(int i = k; i<nums.size(); i++){
           if(max.front() <= i - k) max.pop_front();
            while(!max.empty() && nums[max.back()] <= nums[i]) max.pop_back();
            max.push_back(i);
            ans.push_back(nums[max.front()]);
        }
       
       return ans;
    }
};
