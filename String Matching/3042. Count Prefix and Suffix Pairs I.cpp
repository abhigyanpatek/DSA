class Solution {
    bool isPrefixAndSuffix(string& s1, string& s2){
        if(s1.size() > s2.size()) return false;
        return s2.compare(0, s1.size(), s1) == 0 && s2.compare(s2.size()-s1.size(), s1.size(), s1) == 0;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                count += isPrefixAndSuffix(words[i], words[j]);
            }
        }

        return count;
    }
};