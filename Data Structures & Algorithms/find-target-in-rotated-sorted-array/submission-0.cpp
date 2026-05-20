class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            // Check if we found the target
            if (nums[mid] == target) {
                return mid;
            }
            
            // Left half is sorted
            if (nums[st] <= nums[mid]) {
                // Check if target is inside the sorted left half
                if (nums[st] <= target && target < nums[mid]) {
                    end = mid - 1; // Target is in the left half
                } else {
                    st = mid + 1;  // Target must be in the right half
                }
            } 
            // Right half is sorted
            else {
                // Check if target is inside the sorted right half
                if (nums[mid] < target && target <= nums[end]) {
                    st = mid + 1;  // Target is in the right half
                } else {
                    end = mid - 1; // Target must be in the left half
                }
            }
        }
        
        // Target not found
        return -1;
    }
};