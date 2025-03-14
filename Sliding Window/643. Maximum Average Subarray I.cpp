class Solution {
  public:
      double findMaxAverage(vector<int>& nums, int k) {
          int i = 0, j = 0, sum = 0, ans = INT_MIN;
          while(j < nums.size()){
              sum += nums[j];
              if(j-i+1 == k){
                  ans = max(ans, sum);
                  sum -= nums[i++];
              }
              j++;
          }
          return ans*1.0/k;
      }
  };