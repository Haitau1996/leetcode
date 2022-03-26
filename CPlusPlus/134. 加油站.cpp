/*
Brute Force solution: 34 / 37 个通过测试用例, 超出时间限制
*/
#include <vector>
#include <numeric>
#include <queue>
using namespace std;
class BFSolution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff{};
        int n = gas.size();
        for(int i = 0; i < n; ++i){
            diff.push_back(gas[i] - cost[i]);
        }
        if(accumulate(diff.begin(), diff.end(),0) < 0) return -1;
        for(int i = 0;  i< n; ++i){
            int sum = 0;
            int j = 0;
            while( j < n){
                sum += diff[(j+i)%n];
                if(sum < 0) break;
                else ++j;
            }
            if(j == n) return i;
        }
        return -1;
    }
};
/*
使用一个优先队列，类似于贪心， 先处理差最大的位置， 依次类推
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff{};
        int n = gas.size();
        for(int i = 0; i < n; ++i){
            diff.push_back(gas[i] - cost[i]);
        }
        if(accumulate(diff.begin(), diff.end(),0) < 0) return -1;
        auto cmp = [&diff](int i, int j){
            return diff[i] < diff[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < n; ++i){
            pq.push(i);
        }
        while(!pq.empty()){
            int i = pq.top();
            pq.pop();
            int sum = 0;
            int j = 0;
            while( j < n){
                sum += diff[(j+i)%n];
                if(sum < 0) break;
                else ++j;
            }
            if(j == n) return i;
        }
        return -1;
    }
};
