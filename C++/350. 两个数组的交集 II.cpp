/*
执行用时：4 ms, 在所有 C++ 提交中击败了90.37% 的用户
内存消耗：9.5 MB, 在所有 C++ 提交中击败了99.79% 的用户
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res{};
        std::sort(nums1.begin(),nums1.end());
        std::sort(nums2.begin(),nums2.end());
        for(auto iter1{nums1.begin()}, iter2{nums2.begin()}; 
            iter1 != nums1.end()&&iter2!=nums2.end();  
            /* update iter1 2 in the body */){
                if(*iter1 == *iter2){
                    res.push_back(*iter1);
                    ++iter1;
                    ++iter2;
                }
                else if(*iter1 > * iter2){
                    ++iter2;
                }
                else ++iter1;
        }
        return res;
    }
};