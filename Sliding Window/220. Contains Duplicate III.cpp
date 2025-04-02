class Solution {
  public:
      bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int v) {
          set<int> set;
          for(int i = 0, j = 0; j < nums.size(); j++){
              int low = nums[j] - v;
              int high = nums[j] + v;
              auto it = set.lower_bound(low);
              if(it != set.end() && *it <= high){
                  return true;
              }
              set.insert(nums[j]);
              if(j-i+1 > k){
                  set.erase(nums[i++]);
              }
          }
          return false;
      }
  };