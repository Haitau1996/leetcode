#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        unordered_map<int, int> A;
        unordered_map<int, int> B;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                A[nums1[i] + nums2[j]]++;
            }
        }
        for (int i = 0; i < nums3.size(); ++i) {
            for (int j = 0; j < nums4.size(); ++j) {
                B[nums3[j] + nums4[i]]++;
            }
        }
        int res { 0 };
        for (const auto& elem : A) {
            auto first = elem.first;
            auto second = elem.second;
            auto iter = B.find(-first);
            if (iter != B.end()) {
                res += second * iter->second;
            }
        }
        return res;
    }
};
