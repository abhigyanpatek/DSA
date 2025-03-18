class Solution {
  public:
      bool isNice(string& s, int low, int high) {
          unordered_map<char, int> map;
          while(low <= high) {
              map[s[low]]++;
              low++;
          }
          for(auto& it : map){
              if(!map.count(it.first^32)) return false;
          }
          return true;
      }
      string longestNiceSubstring(string s) {
          string result;
          for(int i = 0; i < s.size(); i++) {
              for(int j = i; j < s.size(); j++){
                  if(isNice(s, i, j) && j-i+1 > result.length()){
                      result = s.substr(i, j-i+1);
                  }
              }
          }
          return result;
      }
  };