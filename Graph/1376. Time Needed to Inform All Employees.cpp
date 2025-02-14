class Solution {
  public:
      int dfs(int node, vector<int> adj[], vector<int>& informTime) {
          int res = 0;
  
          for(auto it: adj[node]){
              res = max(res, dfs(it, adj, informTime));
          }
  
          return res + informTime[node];
      }
  
      int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
          vector<int> adj[n];
          for(int i = 0; i < n; i++){
              if(i != headID)
                  adj[manager[i]].push_back(i);
          }
  
          return dfs(headID, adj, informTime);
      }
  };