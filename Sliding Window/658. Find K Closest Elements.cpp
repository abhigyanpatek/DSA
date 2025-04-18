class Solution {
  public:
      vector<int> findClosestElements(vector<int>& arr, int k, int x) {
          priority_queue<pair<int, int>> maxH;
          for(int i = 0; i < arr.size(); i++){
              maxH.push({abs(arr[i]-x), arr[i]});
              if(maxH.size() > k) maxH.pop();
          }
          vector<int> ans;
          while(size(maxH)){
              ans.push_back(maxH.top().second);
              maxH.pop();
          }
          sort(ans.begin(), ans.end());
          return ans;
      }
  };