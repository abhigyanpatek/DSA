class Solution {
  public:
      vector<int> findSubstring(string str, vector<string>& words) {
          unordered_map<string, int> map;
          vector<int> ans;
          int wordSize = words[0].size();
          int windowSize = words.size()*wordSize;
          for(auto& w: words) map[w]++;
          for(int i = 0; i < wordSize; i++){
              auto mp = map;
              for(int s = i, e = i, count = 0; e + wordSize-1 < str.size(); e+=wordSize){
                  auto w1 = str.substr(e, wordSize);
                  auto it = map.find(w1);
                  count += it != map.end() && it->second-- > 0;
                  if(e+wordSize - s == windowSize){
                      if(count == words.size()) ans.push_back(s);
                      auto w2 = str.substr(s, wordSize);
                      auto it = map.find(w2);
                      count -= it != map.end() && ++it->second > 0;
                      s += wordSize;
                  }
              }
              map.swap(mp);
          }
          return ans;
      }
  };