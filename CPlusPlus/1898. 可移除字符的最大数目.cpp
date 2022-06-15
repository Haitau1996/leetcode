// 二分查找， 每次看删除了前 mid 个元素后剩下的字符串是否可能有子序列 p
// 有个 trick, 删除的时候无需删除， 只需要将它改成 toupper 验证完了再改回去

#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& r)
    {
        int low = 0;
        int high = r.size();
        while (low < high) {
            int mid = (low + high + 1) >> 1;
            for (int i = 0; i < mid; ++i) {
                s[r[i]] = toupper(s[r[i]]);
            }
            if (is_subseq(s, p)) {
                low = mid;
            } else {
                high = mid - 1;
            }
            for (int i = 0; i < mid; ++i) {
                s[r[i]] = tolower(s[r[i]]);
            }
        }
        return low;
    }

private:
    bool is_subseq(string& s, string& p)
    {
        int is = 0;
        int ip = 0;
        while (is < s.size() && ip < p.size()) {
            if (s[is] == p[ip]) {
                ++is;
                ++ip;
            } else {
                ++is;
            }
        }
        return ip == p.size();
    }
};
