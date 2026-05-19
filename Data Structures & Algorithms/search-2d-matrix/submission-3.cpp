class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st1 =0, end1= matrix.size()-1;
        int st2 = 0, end2 = matrix[0].size()-1;
       
   

        while (st1 < end1) {
    int mid = st1 + (end1 - st1 + 1) / 2;  // upper-mid to avoid infinite loop
    if (matrix[mid][0] <= target)
        st1 = mid;
    else
        end1 = mid - 1;
}
int row = st1;
         while(st2<=end2){
           int mid = st2 + (end2 - st2)/2;
            if (matrix[row][mid] > target ) end2 = mid-1;
            else if(matrix[row][mid] < target) st2 = mid+1;
            else  return true;
        }
        return false;

    }
};
