class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    
        unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            // 1. If the element is already in our window, we found a match!
            if (s.count(nums[i])) {
                return true;
            }
            
            // 2. Otherwise, add the current element to the window
            s.insert(nums[i]);
            
            // 3. If the window size exceeds k, remove the oldest element
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};
