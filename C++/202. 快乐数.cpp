/*
在遇到可能无限循环的问题的时候， 在非链表的情况下也可以考虑快慢指针的处理方法
1. 如果有循环， 快慢指针一定能碰上
2. 如果没有循环， 就会遇到终点， 如 nullptr, 如这里的 1
*/
class Solution {
public:
    bool isHappy(int n) {
        int fast = convert(n);
        int slow = n;
        while(fast!=slow){
            slow = convert(slow);
            fast = convert(convert(fast));
        }
        return slow == 1;
    }
private:
    int convert(int n){
        int result = 0;
        int remainder{};
        while(n){
            remainder = n % 10;
            result += (remainder * remainder);
            n/=10;
        }
        return result;
    }
};