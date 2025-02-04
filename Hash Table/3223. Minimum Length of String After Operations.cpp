class Solution {
public:
    int minimumLength(string s) {
        int hash[26] = {}, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            hash[s[i]-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(hash[i]) ans += hash[i]&1? 1: 2;
        }
        return ans;
    }
};