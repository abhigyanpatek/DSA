class Solution {
  public:
      vector<double> medianSlidingWindow(vector<int>& nums, int k) {
          vector<double> ans;
          multiset<int, greater<int>> smaller;
          multiset<int> larger;
          auto median = [&]() -> double{
              if(smaller.size() > larger.size()){
                  return *smaller.begin();
              }else if(smaller.size() < larger.size()){
                  return *larger.begin();
              }else{
                  return (*smaller.begin()*1.0 + *larger.begin())/2;
              }
          };
          auto balance = [&](){
              int s = smaller.size(), l = larger.size();
              if(s - l> 1){
                  larger.insert(*smaller.begin());
                  smaller.erase(smaller.begin());
              }
              if(l - s> 1){
                  smaller.insert(*larger.begin());
                  larger.erase(larger.begin());
              }
          };
          for(int i = 0, j = 0; j < nums.size(); j++){
              // calculation me add krlete h
              if(smaller.empty() || nums[j] <= *smaller.begin()){
                  smaller.insert(nums[j]);
              }else{
                  larger.insert(nums[j]);
              }
              balance();
              if(j-i+1 == k){
                  ans.push_back(median());
                  // sliding the window
                  auto it = smaller.find(nums[i]);
                  if(it != smaller.end()){
                      smaller.erase(it);
                  }else{
                      it = larger.find(nums[i]);
                      larger.erase(it);
                  }
                  balance();
                  i++;
              } 
          }
          return ans;
      }
  };