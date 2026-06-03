class Solution {
public:
    bool check( vector<vector<char>>& board, char x, int row , int col ){
           if( board[row][col] == x){
            return true;
           } return false;
    }

      bool present(vector<vector<char>>& board, string word, int i, int row, int col) {
    if(i == word.length()) return true;

    // ✅ Mark current cell as visited
    char temp = board[row][col];
    board[row][col] = '#';

    // up 
    if(row-1 >= 0 && board[row-1][col] != '#') {  // ✅ check # instead of prerow
        if(check(board, word[i], row-1, col)) {
            if(present(board, word, i+1, row-1, col)) {
                board[row][col] = temp; // ✅ restore before returning
                return true;
            }
        }
    }
    // down
    if(row+1 < board.size() && board[row+1][col] != '#') {
        if(check(board, word[i], row+1, col)) {
            if(present(board, word, i+1, row+1, col)) {
                board[row][col] = temp;
                return true;
            }
        }
    }
    // left
    if(col-1 >= 0 && board[row][col-1] != '#') {
        if(check(board, word[i], row, col-1)) {
            if(present(board, word, i+1, row, col-1)) {
                board[row][col] = temp;
                return true;
            }
        }
    }
    // right
    if(col+1 < board[0].size() && board[row][col+1] != '#') {
        if(check(board, word[i], row, col+1)) {
            if(present(board, word, i+1, row, col+1)) {
                board[row][col] = temp;
                return true;
            }
        }
    }

    board[row][col] = temp; // ✅ restore on failure too
    return false;
}
    
    bool find(vector<vector<char>>& board, string word , int row , int col   ){
        
          if ( col == board[0].size()){
            row++;
            col = 0;
          }

        if(row == board.size()) return false;

          if( board[row][col] == word[0] ){
            if(present( board , word , 1 , row , col)) return true;
             
          }
          return  find( board , word , row, col+1);

    }

    bool exist(vector<vector<char>>& board, string word) {
        
        return find( board , word , 0,0); 
    }
};
