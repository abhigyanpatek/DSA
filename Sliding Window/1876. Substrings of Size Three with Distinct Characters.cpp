class Solution {
  public:
      int countGoodSubstrings(string s) {
          int hash[26] = {};
          int i = 0, j = 0, count = 0, ans = 0;
          while(j < s.size()){
              if(!hash[s[j]-'a']) count++;
              hash[s[j]-'a']++;
              if(j-i+1 == 3){
                  if(count == 3) ans++;
                  hash[s[i]-'a']--;
                  if(hash[s[i]-'a'] == 0) count--;
                  i++;
              }
              j++;
          }
          return ans;
      }
  };