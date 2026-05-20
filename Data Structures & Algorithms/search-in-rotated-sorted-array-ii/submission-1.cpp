class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            // Target found
            if (nums[mid] == target) return true;
            
            // THE NEW EDGE CASE: Shrink the search space if we can't tell which half is sorted
            if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
                st++;
                end--;
                continue; // Skip the rest of the loop and recalculate mid
            }
            
            // Left half is sorted
            if (nums[st] <= nums[mid]) {
                if (nums[st] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } 
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        
        return false;
    }
};