class Solution {
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        return core(x, n);
    }
    double core(double x, long long n)
    {
        if (n < 0)
            return 1 / core(x, -n);
        if (n == 0)
            return 1;
        double half = core(x, n / 2);
        return n & 1 ? half * half * x : half * half;
    }
};
