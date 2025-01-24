class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, INT_MAX), last(26); 
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            first[s[i]-'a'] = min(first[s[i]-'a'], i);
            last[s[i]-'a'] = i;
        }
        for(int i = 0; i < 26; ++i){
            if(last[i]-first[i] > 1){
                unordered_set<char> set(s.begin()+first[i]+1, s.begin()+last[i]);
                ans += set.size();
            }
        }
        return ans;
    }
};