class Solution {
  public:
      int minimumDifference(vector<int>& nums, int k) {
          sort(nums.begin(), nums.end());
          int i = 0, j = 0, ans = INT_MAX;
          while(j < nums.size()){
              if(j-i+1 == k){
                  ans = min(ans, abs(nums[i]- nums[j]));
                  i++;
              }
              j++;
          }
          return ans;
      }
  };