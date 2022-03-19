/* 
 * 做法 1 ： 暴力解法， 47 / 53 个通过测试用例， 超时
 * O(N^2)
*/
#include <vector>
#include <limits>
using namespace std;
class BrutalForceSolution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = numeric_limits<int>::min();
        int n = static_cast<int>(values.size());
        for(int i = 1; i < n ; ++i){
            for(int j = 0; j < i; ++j){
                if((values[i]+values[j] - (i -j)) > result){
                    result = values[i]+values[j] - (i -j);
                }
            }
        }
        return result;
    }
};
/* 
 * 做法 2 ： 动态编程， 使用一个vector dp， dp[i] 存放第 i 个数之前能选的最优值， 即 最好的 value[j]+i-j
 * dp[i] = max(dp[i-1],value[i-1]) - 1, 意思就是，要么是选前一个数， 要么选前一个数的最优值， 然后减去 1 的距离
 * 然后遍历大于 1 的每个 i, 寻求 dp[i] + value[i] 的最大值 
 * O(N)
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = numeric_limits<int>::min();
        int n = static_cast<int>(values.size());
        vector<int> current_best(n, 0);
        for(int i = 1; i < n; ++i){
            current_best[i] = max(values[i-1],current_best[i-1]) - 1;
        }
        for(int i = 1; i < n ; ++i){
            if(current_best[i] + values[i] > result) result = current_best[i] + values[i];
        }
        return result;
    }
};
