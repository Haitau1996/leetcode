// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem67.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 * 100 & 65.78
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        return a.size() > b.size() ? addHelper(a,b) : addHelper(b,a);
    }
private:
    string addHelper(string& a, string& b) {
        int carry = 0;
        auto cursorA = a.rbegin();
        auto cursorB = b.rbegin();
        while(cursorB != b.rend()){
            int a_int = (*cursorA) - '0';
            int b_int = (*cursorB) - '0';
            int sum = a_int + b_int + carry;
            if(sum >= 2) {
                sum -= 2;
                carry = 1;
            }
            else{
                carry = 0;
            }
            *cursorA = sum + '0';
            ++cursorB;
            ++cursorA;
        }
        while(cursorA!=a.rend() && carry){
            int sum = (*cursorA) - '0' + carry;
            if(sum >= 2) {
                sum -= 2;
                carry = 1;
            }else{
                carry = 0;
            }
            *cursorA = sum + '0';
            ++cursorA;
        }
        return carry? to_string(1)+a : a;
    }
};
// @lc code=end

