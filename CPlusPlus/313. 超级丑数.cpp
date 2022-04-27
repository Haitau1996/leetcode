// 使用优先队列暴力枚举
// 时间复杂度 n * m * log(n)
// TODO: 使用动态规划优化
#include <queue>
#include <unordered_set>

using namespace std;
class BFSolution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        auto cmp = [](const int& a, const int& b) {
            return a > b;
        };
        unordered_set<int> checked {};
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        pq.push(1);
        checked.emplace(1);
        int curr = 0;
        while (curr < n && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ++curr;
            if (curr == n)
                return top;
            else {
                for (const auto& elem : primes) {
                    long next = top * (long)elem;
                    if (checked.find(next) == checked.end() && next < numeric_limits<int>::max()) {
                        pq.push(next);
                        checked.emplace(next);
                    }
                }
            }
        }
        return curr;
    }
};
