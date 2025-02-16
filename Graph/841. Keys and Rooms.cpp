class Solution {
  public:
      bool canVisitAllRooms(vector<vector<int>>& rooms) {
          int n = rooms.size();
          vector<bool> vis(n);
          int count = 0;
          queue<int> q;
          count++;
          vis[0] = true;
          q.push(0);
          while(!q.empty()){
              int node = q.front(); q.pop();
              for(auto& it : rooms[node]){
                  if(!vis[it]){
                      count++;
                      vis[it] = true;
                      q.push(it);
                  }
              }
          }
          return count == n;
      }
  };