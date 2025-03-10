class Solution {
  public:
      int myAtoi(string s) {
          int result = 0;
          long long ans = 0, pV = 1;
          bool negativeSign = false, flag = false;
          
          for(int i = 0; i < s.length(); i++){
              if(isalpha(s[i]) || s[i] == '.') break;
              if(i < s.length()-1 && (s[i] == '-' || s[i] == '+')){
                  if(isdigit(s[i+1]) && s[i] == '-') negativeSign = true;
                  else if(isdigit(s[i+1]) && s[i] == '+') negativeSign = false;
                  else break;
              } 
              while(i < s.length() && isdigit(s[i])){
                  if(ans > INT_MAX) return negativeSign ? INT_MIN: INT_MAX;
                  ans = ans*10 + (s[i]-'0');
                  flag = true;
                  i++;
              }
              if(flag) break;
          }
          if(ans > INT_MAX) return negativeSign ? INT_MIN: INT_MAX;
          return negativeSign? -ans: ans;
      }
  };