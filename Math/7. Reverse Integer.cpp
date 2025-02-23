class Solution {
  public:
      int reverse(int x) {
          int rev = 0;
          int mini = INT_MIN/10, maxi = INT_MAX/10;
          while(x != 0){
              int rem = x%10;
              
              if(rev > maxi or rev == maxi and rem > 7) return 0;
              if(rev < mini or rev == mini and rem > 8) return 0;
              
              rev = rev*10 + rem;
              x /= 10;
          }
          return rev;
      }
  };