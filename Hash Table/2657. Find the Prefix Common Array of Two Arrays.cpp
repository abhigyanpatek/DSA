class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> set;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            set.insert(A[i]);
            int count = 0;
            for(int j = 0; j <= i; j++) {
                count += set.find(B[j]) != set.end();
            }
            res.push_back(count);
        }
        return res;
    }
};