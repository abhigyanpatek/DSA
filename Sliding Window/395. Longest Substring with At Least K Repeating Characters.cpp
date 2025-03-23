class Solution {
  public:
      int longestSubstring(string s, int k) {
          int n = s.size();
          int max_len = 0;
          for (int i = 0; i < n; i++) {
              std::unordered_map<char, int> char_counts;
              int unique_char_count = 0;
              int no_less_than_k_count = 0;
              for (int j = i; j < n; j++) {
                  if (char_counts[s[j]] == 0) {
                      unique_char_count++;
                  }
                  char_counts[s[j]]++;
                  if (char_counts[s[j]] == k) {
                      no_less_than_k_count++;
                  }
                  if (unique_char_count == no_less_than_k_count) {
                      max_len = std::max(max_len, j - i + 1);
                  }
              }
          }
          return max_len;
      }
  };