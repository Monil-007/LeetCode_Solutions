class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = to_string(n);
        int mul = 1, sum = 0;
        for(auto x: s) {
            int v = x - '0';
            mul *= v;
            sum += v;
        }
        return mul - sum;
    }
};