class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int hash[26] = {};
        vector<string> res;
        for(auto& b: words2) {
            int temp[26] = {};
            for(auto& c: b) {
                hash[c-'a'] = max(hash[c-'a'], ++temp[c-'a']);
            }
        }
        for(auto& a: words1) {
            int hash2[26] = {}, i = 0;
            for(auto& c: a) {
                hash2[c-'a']++;
            }
            for(; i < 26; i++) {
                if(hash[i] > hash2[i]) break;
            }
            if(i == 26) res.push_back(a);
        }
        return res;
    }
};