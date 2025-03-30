class Solution {
  public:
      int minimumRecolors(string blocks, int k) {
          int i = 0, j = 0, countOfWhite = 0, ans = INT_MAX;
          while(j < blocks.length()){
              if(blocks[j] == 'W') countOfWhite++;
              if(j-i+1 == k){
                  ans = min(ans, countOfWhite);
                  if(blocks[i] == 'W') countOfWhite--;
                  i++;
              }
              j++;
          }
          return ans;
      }
  };