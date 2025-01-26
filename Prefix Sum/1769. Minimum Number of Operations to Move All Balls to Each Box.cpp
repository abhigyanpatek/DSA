class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), left = 0, right = 0, prefix = 0, suffix = 0;
        vector<int> answer(n);
        for(int i = 0, j = n-1; i < n; i++, j--){
            answer[i] += prefix + left;
            prefix += left;
            left += boxes[i] == '1';

            answer[j] += suffix + right;
            suffix += right;
            right += boxes[j] == '1';
        }
        return answer;
    }
};