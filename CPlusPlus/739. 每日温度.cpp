#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<int> monoStack {};
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!monoStack.empty() && temperatures[monoStack.top()] < temperatures[i]) {
                res[monoStack.top()] = i - monoStack.top();
                monoStack.pop();
            }
            monoStack.push(i);
        }
        return res;
    }
};
