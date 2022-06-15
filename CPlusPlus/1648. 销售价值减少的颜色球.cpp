// 销售完成之后的最大元素为 val, 它的范围是 [0, max(inventory)]
// 如果对于某个 mid = (left + right)/2, 需要的订单大于 orders, 说明 mid 选小了， 导致卖出了很多不该卖的元素
// 需要特别注意这个关系不要搞反
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders)
    {
        sort(inventory.begin(), inventory.end());
        int left = 0;
        int right = inventory.back();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (count_orders(inventory, mid, orders)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        long long res {};
        const int MOD = 1000000007;
        int pos = upper_bound(inventory.begin(), inventory.end(), left) - inventory.begin();
        while (pos < inventory.size()) {
            res = (res + ((long long)(left + 1 + inventory[pos]) * (long long)(inventory[pos] - left) / 2) % MOD) % MOD;
            orders -= (inventory[pos] - left);
            ++pos;
        }
        res = (res + (long long)(left)*orders) % MOD;
        return res;
    }

private:
    bool count_orders(vector<int>& inv, int val, int orders)
    {
        int pos = upper_bound(inv.begin(), inv.end(), val) - inv.begin();
        int cnt {};
        while (pos < inv.size()) {
            cnt += (inv[pos] - val);
            if (cnt > orders)
                return false;
            else {
                ++pos;
            }
        }
        return true;
    }
};
