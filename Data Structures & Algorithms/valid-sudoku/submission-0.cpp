class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       
        // each row;
        for (int i =0; i<9; i++){
            unordered_set<char>s;
            for (int j = 0; j<9; j++){
                if (board[i][j] == '.') continue;
                if (s.count(board[i][j])) return false;

                s.insert(board[i][j]);
            }
         }

         // each column
          for (int i =0; i<9; i++){
            unordered_set<char>s;
            for (int j = 0; j<9; j++){
                if (board[j][i] == '.') continue;
                if (s.count(board[j][i])) return false;

                s.insert(board[j][i]);
            }
         }

         // each 3x3 block
        
          for (int i =0; i<3; i++){
            
            for (int j = 0; j<3; j++){
              unordered_set<char>s; 

              for (int x=0; x<3; x++){
                for (int y=0; y<3; y++){

                    char shell = board[i*3 + x][j*3 + y];
                    if (shell == '.') continue;
                    if (s.count(shell)) return false;

                     s.insert(shell);
            }
                    
                }
              }  
            
         }

return true;
    }
};
