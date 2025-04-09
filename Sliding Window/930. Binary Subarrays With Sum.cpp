class Solution {
  public:
      int numSubarraysWithSum(vector<int>& nums, int goal) {
          unordered_map<int,int> map;
          map[0] = 1;
          int sum = 0, ans = 0;
          for(int& x : nums){
              sum += x;
              if(map.count(sum-goal)){
                  ans += map[sum-goal];
              }
              map[sum]++;
          }
          return ans;
      }
  };