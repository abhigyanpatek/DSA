class Solution {
  public:
      int divisorSubstrings(int num, int k) {
          int n = 0, nums = num, pV = 1, ans = 0;
          while(nums > 0){
              n += (nums%10)*pV;
              if(--k > 0) pV *= 10;
              else{
                  ans += n && num%n == 0;
                  n /= 10;
              }
              nums /= 10;
          }
          return ans;
      }
  };