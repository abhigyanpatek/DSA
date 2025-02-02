class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()) return false;
        if(k == s.size()) return true;

        int countOfOdd = 0;
        for(char& c: s) {
            countOfOdd ^= 1 << c-'a';
        }
        return __builtin_popcount(countOfOdd) <= k;
    }
};