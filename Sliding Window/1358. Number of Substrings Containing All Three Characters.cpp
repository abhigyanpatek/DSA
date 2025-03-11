class Solution {
  public:
      int numberOfSubstrings(string s) {
          int ans = 0, hash[3] = {}, count = 0, n = s.size();
          for(int i = 0, j = 0; j < n; j++){
              if(++hash[s[j]-'a'] == 1){
                  count++;
              }
              while(count == 3){
                  ans += n-j;
                  if(--hash[s[i]-'a'] == 0){
                      count--;
                  }
                  i++;
              }
          }
          return ans;
      }
  };