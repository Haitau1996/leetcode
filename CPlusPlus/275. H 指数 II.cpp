/*
 * 典型的二分查找， 就是要特别注意有没有包含 下标指向的那篇文章
 */
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        int left = 0;
        int right = citations.back();
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (valid(citations, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

private:
    bool valid(vector<int>& citations, int index)
    {
        auto cnt = distance(lower_bound(citations.begin(), citations.end(), index), citations.end());
        return cnt >= index;
    }
};
