/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    // Step 1: Find peak index
    int findPeak(MountainArray& arr, int n) {
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr.get(mid) < arr.get(mid + 1))
                lo = mid + 1;  // ascending side, peak is to the right
            else
                hi = mid;      // descending side, peak is here or left
        }
        return lo; // lo == hi == peak
    }

    // Step 2: Binary search on ascending segment [lo, hi]
    int bsAsc(MountainArray& arr, int target, int lo, int hi) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = arr.get(mid);
            if (val == target) return mid;
            else if (val < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

    // Step 3: Binary search on descending segment [lo, hi]
    int bsDesc(MountainArray& arr, int target, int lo, int hi) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = arr.get(mid);
            if (val == target) return mid;
            else if (val > target) lo = mid + 1;  // descending: go right for smaller
            else hi = mid - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();

        // 1. Find peak
        int peak = findPeak(mountainArr, n);

        // 2. Search ascending left side [0, peak]
        int idx = bsAsc(mountainArr, target, 0, peak);
        if (idx != -1) return idx;  // prefer smaller index

        // 3. Search descending right side [peak+1, n-1]
        return bsDesc(mountainArr, target, peak + 1, n - 1);
    }
};