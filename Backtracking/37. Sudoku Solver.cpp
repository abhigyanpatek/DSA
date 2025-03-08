class Solution {
  public:
      bool isValid(int row, int col, char c, vector<vector<char>>& board){
          for(int i = 0; i < 9; i++){
              if(board[row][i] == c) return false;
              if(board[i][col] == c) return false;
              if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
          }
          return true;
      }
      
      bool helper(int i, int j, vector<vector<char>>& board){
          if(j == 9) return helper(i+1, 0, board);
          if(i == 9) return true;
          
          if(board[i][j] != '.') return helper(i, j+1, board);
          for(char c = '1'; c <= '9'; c++){
              if(isValid(i, j, c, board)){
                  board[i][j] = c;
                  if(helper(i, j+1, board)) return true;
                  board[i][j] = '.';
              }
          }
          return false;
      }
      void solveSudoku(vector<vector<char>>& board) {
          helper(0, 0, board);
      }
  };