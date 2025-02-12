class Solution {
  public:
      bool dfs(vector<int> adj[], int node, int destination, vector<bool>& visited) {
          if (node == destination) return true;
          visited[node] = true;
          for (auto it: adj[node]) {
              if (!visited[it] && dfs(adj, it, destination, visited)) {
                  return true;
              }
          }
          return false;
      }
      bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
          vector<int> adj[n];
          vector<bool> visited(n);
          for(auto& e: edges) {
              adj[e[0]].push_back(e[1]);
              adj[e[1]].push_back(e[0]);
          }
          
          return dfs(adj, source, destination, visited);
      }
  };