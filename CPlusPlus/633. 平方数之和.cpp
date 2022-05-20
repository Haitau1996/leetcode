class Solution {
public:
    bool judgeSquareSum(int c)
    {
        long long left = 0;
        long long right = 0;
        while (right * right <= c) {
            ++right;
        }
        while (left <= right) {
            if (right * right + left * left == c)
                return true;
            else if (right * right + left * left < c)
                ++left;
            else
                --right;
        }
        return false;
    }
};
