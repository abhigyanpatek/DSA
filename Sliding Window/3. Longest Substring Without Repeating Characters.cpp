class Solution {
  public:
      int lengthOfLongestSubstring(string str) {
          vector<int> map(256, -1);
          int ans = 0;
          for(int s = 0, e = 0; e < str.size(); e++){
              if(map[str[e]] != -1){
                  s = max(s, map[str[e]] + 1);
              }
              map[str[e]] = e;
              ans = max(ans, e-s+1);
          }
          return ans;
      }
  };