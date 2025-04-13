class Solution {
  public:
      vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          priority_queue<pair<int,int>> maxH;
          vector<int> ans;
          int i = 0, j = 0;
          while(j < nums.size()){
              maxH.push({nums[j], j});
              if(j-i+1 == k){
                  ans.push_back(maxH.top().first);
                  while(size(maxH) && maxH.top().second <= i) maxH.pop();
                  i++;
              }
              j++;
          }
          return ans;
      }
  };