/*
其实就是考察有多少个完全平方数
除了完全平方数， 其他数字的因子是成对出现的， 除了 1 和 它本身， 刚好相互抵消， 而 1 和本身又相当于灯关了， 但是完全平方数就不同了
*/
class Solution {
public:
    int bulbSwitch(int n) {
        return floor(sqrt(n));
    }
};
