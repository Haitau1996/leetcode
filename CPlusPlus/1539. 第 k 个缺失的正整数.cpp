#include <vector>

using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        int curr = 0;
        int i = 0;
        int n = arr.size();
        while (i <= n && k > 0) {
            if (i == n || arr[i] - curr > k) {
                return curr + k;
            } else {
                k -= (arr[i] - curr - 1);
                curr = arr[i++];
            }
        }
        return 0;
    }
};
