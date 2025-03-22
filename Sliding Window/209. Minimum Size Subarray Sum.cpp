class Solution {
  public:
      bool isFind(vector<int>& arr, int k, int target){
          for(int sum = 0, i = 0, j = 0; j < arr.size(); j++){
              sum += arr[j];
              if(j-i+1 == k){
                  if(sum >= target) return true;
                  sum -= arr[i++];
              }
          }
          return false;
      }
      int minSubArrayLen(int target, vector<int>& nums) {
          int low = 1, high = nums.size(), ans = INT_MAX;
          while(low <= high){
              int k = low + (high-low)/2;
              if(isFind(nums, k, target)){
                  ans = min(ans, k);
                  high = k-1;
              }else{
                  low = k+1;
              }
          }
          return ans == INT_MAX? 0: ans;
      }
  };