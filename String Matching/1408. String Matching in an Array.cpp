class Solution {
    bool compare(string& s, string& target) {
        if(target.size() > s.size()) return false;
        int k = target.size();
        for(int i = 0; i <= s.size()-k; i++){
            int c = 0;
            for(int j = i; j < k + i; j++, c++){
                if(target[c] != s[j]) break;
            }
            if(c == k) return true;
        }

        return false;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> set;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words.size(); j++) {
                if(i != j && compare(words[j], words[i])) {
                    set.insert(words[i]);
                }
            }
        }
        vector<string> ans(set.begin(), set.end());
        return ans;
    }
};