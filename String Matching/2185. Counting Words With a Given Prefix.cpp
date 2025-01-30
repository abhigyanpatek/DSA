class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(auto& w: words) {
            count += w.compare(0, pref.size(), pref) == 0;
        }
        return count;
    }
};