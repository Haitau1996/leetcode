// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem167.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int beg = 0;
        int end = numbers.size() - 1;
        while(beg < end) {
            if(numbers[beg] + numbers[end] < target) ++beg;
            else if(numbers[beg] + numbers[end] > target) --end;
            else break;
        }
        return vector<int>{beg+1, end+1};
    }
};
// @lc code=end

