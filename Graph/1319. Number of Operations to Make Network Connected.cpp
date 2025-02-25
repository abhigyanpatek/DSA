class DSU {
  public:
      vector<int> parent, rank;
      DSU(int n) : parent(n), rank(n, 0) {
          for (int i = 0; i < n; i++) {
              parent[i] = i;
          }
      }
  
      int find_set(int x) {
          if (x == parent[x]) return x;
          return parent[x] = find_set(parent[x]);
      }
  
      bool union_sets(int u, int v) {
          u = find_set(u), v = find_set(v);
          if(u == v) return false;
  
          if(rank[v] < rank[u]) {
              parent[v] = u;
          } else if(rank[u] < rank[v]) {
              parent[u] = v;
          } else {
              parent[v] = u;
              rank[u]++;
          }
          return true;
      }
  };
  class Solution {
  public:
      int makeConnected(int n, vector<vector<int>>& connections) {
          if(connections.size() < n-1) return -1;
          DSU uf(n);
          int extraCables = 0;
          unordered_set<int> visited;
          for (auto& connection: connections) {
              extraCables += !uf.union_sets(connection[0], connection[1]);
              visited.insert(connection[0]);
              visited.insert(connection[1]);
          }
          return n-visited.size() > extraCables? -1: n-visited.size();
      }
  };