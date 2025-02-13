class Solution {
  public:
      void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& res) {
          path.push_back(node);
          if (node == graph.size()-1) {
              res.push_back(path);
          }
          for (auto it: graph[node]) {
              dfs(it, graph, path, res);
          }
          path.pop_back();
      }
  
      vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
          vector<vector<int>> res;
          vector<int> path;
          dfs(0, graph, path, res);
          return res;
      }
  };