class Solution {
  public:
      int totalFruit(vector<int>& fruits) {
          unordered_map<int, int> map;
          int ans = 0;
          for(int i = 0, j = 0; j < fruits.size(); j++){
              map[fruits[j]]++;
              if(map.size() > 2){
                  if(--map[fruits[i]] == 0) map.erase(fruits[i]);
                  i++;
              }
              ans = max(ans, j-i+1);
          }
          return ans;
      }
  };