class Solution {
public:

   bool issafe( int row, int col  ,vector<string>& board , int n    ){

   // vertical
   for(int i=0; i<row; i++){
      if(board[i][col] == 'Q') return false;

   }

   // Main Diagonal
      for(int i = row-1 , j = col-1; i>=0 && j>=0; i--,j-- ){
         if(board[i][j]== 'Q') return false;
      }
   // Other Diagonal
   for(int i = row-1 , j = col+1; i>=0 && j<n; i--,j++ ){
         if(board[i][j]== 'Q') return false;
   }

   return true;
   }



   void helper(vector<vector<string>>& ans ,vector<string>& board, int n , int row){
      if(row == n){
         ans.push_back(board);
         return;
      }
      string s (n , '.');


      for(int col=0; col<n; col++ ){
        
         if(issafe( row , col , board , n  ) ){ 
            s[col] = 'Q';
             board.push_back(s);
            helper(ans , board , n  , row +1);
            board.pop_back();
             s[col] = '.'; 
         }
      }
   }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
       
        vector<string>board;

        helper(ans , board , n  , 0);

        return ans;
    }
};
