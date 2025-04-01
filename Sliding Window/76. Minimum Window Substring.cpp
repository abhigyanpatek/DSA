class Solution {
  public:
      string minWindow(string str, string t) {
          int final_s = -1, len = INT_MAX, hash[58] = {};
          for(char c: t) hash[c-65]++;
          for(int s = 0, e = 0, count = 0; e < str.size(); e++){
              count += hash[str[e]-65]-- > 0;
              while(count == t.size()){
                  if(e-s+1 < len){
                      final_s = s;
                      len = min(len, e-s+1);
                  }
                  count -= ++hash[str[s++]-65] > 0;
              }
          }
          return len != INT_MAX? str.substr(final_s, len): "";
      }
  };