class Solution {
  public:
      vector<char> happy = {'a', 'b', 'c'};
      string dfs(int n, int& k, string& s){
          if(n == 0){
              k--;
              if(k == 0) return s;
              return "";
          }
          
          for(int i = 0; i < 3; i++){
              if(s.length() > 0 && s.back() == happy[i]) continue;
              s.push_back(happy[i]);
              string str = dfs(n-1, k, s);
              if(str.length() != 0) return str;
              s.pop_back();
          }
          return "";
      }
      
      string getHappyString(int n, int k) {
          // vector<char> happy = {'a','b','c'};
          string s;
          return dfs(n, k, s);
      }
  };