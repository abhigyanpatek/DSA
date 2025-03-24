class Solution {
  public:
      int characterReplacement(string s, int k) {
          int hash[26] = {};
          int ans = 0, maxFreq = 0;
          for(int i = 0, j = 0; j < s.length(); j++){
              maxFreq = max(maxFreq, ++hash[s[j]-65]);
              if(j-i+1 - maxFreq > k){
                  --hash[s[i++]-65];
              }else{
                  ans = j-i+1;
              }
          }
          return ans;
      }
  };