class Solution {
  public:
      
      int dfs(int hash[]){
          int ans = 0;
          for(int i = 0; i < 26; i++){
              if(hash[i] == 0) continue;
              hash[i]--;
              ans++;
              ans += dfs(hash);
              hash[i]++;
          }
          return ans;
      }
      
      int numTilePossibilities(string tiles) {
          int hash[26] = {};
          for(char& c : tiles) hash[c-'A']++;
          return dfs(hash);
      }
  };