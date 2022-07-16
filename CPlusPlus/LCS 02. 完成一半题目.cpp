// 哈希 + 排序 + 贪心
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int halfQuestions(vector<int>& questions)
    {
        vector<int> count(1001, 0);
        for (const auto& elem : questions) {
            count[elem]++;
        }
        sort(count.begin(), count.end(), std::greater<int>());
        int curr_count { 0 };
        int upper_bound = questions.size() / 2;
        for (int i = 0; i < count.size(); ++i) {
            curr_count += count[i];
            if (curr_count >= upper_bound)
                return i + 1;
        }
        return count.size();
    }
};
