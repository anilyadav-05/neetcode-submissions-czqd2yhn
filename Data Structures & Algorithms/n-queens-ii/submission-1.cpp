class Solution {
public:
    int count = 0;

    void helper(int row, int n, 
                vector<bool>& cols, 
                vector<bool>& diag1,   // row-col
                vector<bool>& diag2) { // row+col
        if(row == n) {
            count++;
            return;
        }

        for(int col = 0; col < n; col++) {
            if(cols[col] || diag1[row-col+n] || diag2[row+col])
                continue;

            // place
            cols[col] = diag1[row-col+n] = diag2[row+col] = true;
            helper(row+1, n, cols, diag1, diag2);
            // remove
            cols[col] = diag1[row-col+n] = diag2[row+col] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> diag1(2*n, false);  // tracks row-col diagonal
        vector<bool> diag2(2*n, false);  // tracks row+col diagonal
        helper(0, n, cols, diag1, diag2);
        return count;
    }
};