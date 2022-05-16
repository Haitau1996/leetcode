/*
 * 先排序， 然后依次查找， 如果element 它不在哈希表中，则为一个开头, 将 element+ 1 ... element + k-1 这 k-1 个数的 cnt++;
 * 否则的话就将它的计数减一(计数为 0 则删掉)
 */

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
bool isPossibleDivide(vector<int>& nums, int k)
{
    unordered_map<int, int> cnt {};
    sort(nums.begin(), nums.end());
    for (const auto& elem : nums) {
        if (cnt.find(elem) == cnt.end()) {
            for (int i = 1; i < k; ++i) {
                cnt[i + elem]++;
            }
        } else {
            cnt[elem]--;
            if (cnt[elem] == 0) {
                cnt.erase(elem);
            }
        }
    }
    return cnt.empty();
}
