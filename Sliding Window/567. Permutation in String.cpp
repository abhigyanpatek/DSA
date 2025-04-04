class Solution {
  public:
      bool checkInclusion(string s1, string s2) {
          int hash[26] = {};
          for(char c: s1) hash[c-97]++;
          int k = s1.size(), count = 0;
          for(int s = 0, e = 0; e < s2.size(); e++){
              count += hash[s2[e]-97]-- > 0;
              if(e-s+1 == k){
                  if(count == k) return true;
                  count -= ++hash[s2[s++]-97] > 0; 
              }
          }
          return false;
      }
  };