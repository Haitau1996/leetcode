/*
 * 对于每个邮件地址， 保存它第一次出现时候的下标。 如果后续过程中发现邮件出现过， 则将当前下标和保存的下标做 union。
 * 结果去重后的人只需要取 i==find(i) 的那部分， 因为不相等的已经做过了 union。我们此外还要保存 i 个人的名字放在 res 的位置， 方便遍历邮件哈希表时候插入。
 * 注意区分 i 和 j， 经常写错
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        int n = accounts.size();
        idx = vector<int>(n, 0);
        for (int i = 0; i < n; ++i)
            idx[i] = i;
        hit = vector<int>(n, 1);
        unordered_map<string, int> gidx {};
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                auto iter = gidx.find(accounts[i][j]);
                if (iter == gidx.end())
                    gidx[accounts[i][j]] = i;
                else {
                    auto p = iter->second;
                    unite(i, p);
                }
            }
        }
        vector<vector<string>> res {};
        unordered_map<int, int> get_pos;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) {
                res.push_back(vector<string> {});
                res[res.size() - 1].push_back(accounts[i][0]);
                get_pos[i] = res.size() - 1;
            }
        }
        for (const auto& [x, y] : gidx) {
            int pos = get_pos[find(y)];
            res[pos].push_back(x);
        }
        for (auto& curr : res) {
            sort(curr.begin() + 1, curr.end());
        }
        return res;
    }

private:
    vector<int> idx;
    vector<int> hit;
    int find(int i)
    {
        while (i != idx[i]) {
            i = idx[i];
        }
        return i;
    }
    bool unite(int p, int q)
    {
        int pr = find(p);
        int qr = find(q);
        if (pr == qr)
            return false;
        else {
            if (hit[pr] == hit[qr]) {
                idx[pr] = qr;
                hit[qr]++;
            } else if (hit[pr] > hit[qr]) {
                idx[qr] = pr;
            } else {
                idx[pr] = qr;
            }
            return true;
        }
    }
};
