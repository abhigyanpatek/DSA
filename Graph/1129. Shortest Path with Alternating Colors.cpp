class Solution {
  public:
      vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
          vector<vector<int>> redGraph(n), blueGraph(n);
          for (auto& e: redEdges) {
              redGraph[e[0]].push_back(e[1]);
          }
          for (auto& e: blueEdges) {
              blueGraph[e[0]].push_back(e[1]);
          }
  
          vector<int> res(n, -1);
          vector<bool> visited_red(n);
          vector<bool> visited_blue(n);
          queue<vector<int>> q;
          q.push({0, 0, 0}); // red
          q.push({0, 0, 1}); // blue
          visited_red[0] = true;
          visited_blue[0] = true;
          while (q.size()) {
              auto node = q.front()[0]; 
              auto distance = q.front()[1];
              auto lastColor = q.front()[2];
              q.pop();
  
              res[node] = res[node] == -1? distance: res[node];
              auto& graph = lastColor == 0? blueGraph: redGraph;
              auto& visited = lastColor == 0? visited_red: visited_blue;
              for (auto it: graph[node]) {
                  if (!visited[it]) {
                      q.push({it, distance+1, !lastColor});
                      visited[it] = true;
                  }
              }
          }
          return res; 
      }
  };