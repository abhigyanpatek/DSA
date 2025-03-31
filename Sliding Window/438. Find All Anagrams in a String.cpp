class Solution {
  public:
      vector<int> findAnagrams(string str, string p) {
          vector<int> ans, hash(26, 0);
          for(char c: p) hash[c-97]++;
          for(int count = 0, k = p.size(), s = 0, e = 0; e < str.size(); e++){
              count += hash[str[e]-97]-- > 0;
              if(e-s+1 == k){
                  if(count == k) ans.push_back(s);
                  count -= ++hash[str[s++]-97] > 0;
              }
          }
          return ans;
      }
  };