/*
 * 删除子数组的长度在 [0, arr.size()-1] 之间, 可以做二分查找， 对某个值判断是否可行
 * 对于某个特定的长度 val， 可以将数组分成三个部分， [0,...,i-1], [i,..., i+val-1], [i+val,..., i[arr.size()-1]]
 * 某个长度val 和 i 下删除后有序， 则前后两个部分都是有序的， 并且能在中间连接起来
 * 判断两个部分有序需要 O(n) 时间, 可以使用前缀和， 先计算出来， 在 O(1) 时间内查询
 */
#include <vector>

using namespace std;
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr)
    {
        int l = 0;
        int r = arr.size() - 1;
        vector<bool> prefix = vector<bool>(arr.size(), false);
        vector<bool> postfix = vector<bool>(arr.size(), false);
        for (int i = 0; i < arr.size(); ++i) {
            if (i == 0)
                prefix[i] = true;
            else if (arr[i] >= arr[i - 1]) {
                prefix[i] = true;
            } else
                break;
        }
        for (int i = arr.size() - 1; i >= 0; --i) {
            if (i == arr.size() - 1 || arr[i] <= arr[i + 1])
                postfix[i] = true;
            else
                break;
        }
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (valid_delete(arr, mid, prefix, postfix)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

private:
    bool valid_delete(vector<int>& arr, int val, vector<bool>& prefix, vector<bool>& postfix)
    {
        for (int i = 0; i < arr.size(); ++i) {
            if (i + val > arr.size() - 1 || (postfix[i + val] && (i == 0 || arr[i + val] >= arr[i - 1])))
                return true;
            if (!prefix[i])
                return false;
        }
        return true;
    }
};
