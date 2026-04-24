class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.empty()) return 0; 
        
        int j = 1; // Points to where the next unique element should go
        
        // i iterates through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is different from the previous one, it's unique
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i]; // Move it to the front
                j++;               // Increment the unique counter
            }
        }
        
        return j; // j is now the count of unique elements
        
    }
};