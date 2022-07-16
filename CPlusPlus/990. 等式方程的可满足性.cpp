// 简单的并查集练习
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool equationsPossible(vector<string>& equations)
    {
        idx = vector<int>(26, 0);
        for (int i = 0; i < 26; ++i)
            idx[i] = i;
        for (const auto& eq : equations) {
            if (eq[1] == '=') {
                unite(eq[0] - 'a', eq[3] - 'a');
            }
        }
        for (const auto& eq : equations) {
            if (eq[1] == '!' && find(eq[0] - 'a') == find(eq[3] - 'a'))
                return false;
        }
        return true;
    }

private:
    vector<int> idx;
    int find(int p)
    {
        while (p != idx[p]) {
            p = idx[p];
        }
        return p;
    }
    void unite(int p, int q)
    {
        int pr = find(p);
        int qr = find(q);
        if (pr == qr)
            return;
        else {
            idx[pr] = qr;
        }
    }
};
