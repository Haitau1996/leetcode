/* 
* 解法 1： 使用最大堆存放结果， 需要的时间复杂度为 $O(K^2\log K)$
*/
# include <vector>
# include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [](const vector<int>& first, const vector<int> second){
            return (first[0] + first[1]) < (second[0] + second[1]);            
        };
        for(int i = 0; i < k && i < nums1.size(); i++){
            for(int j = 0; j < k && j < nums2.size(); j++){
                if(result.empty()){
                    result.push_back(vector<int>{nums1[i],nums2[j]});
                    make_heap(result.begin(), result.end(), cmp);
                }
                else if(result.size() < k){
                    result.push_back(vector<int>{nums1[i],nums2[j]});
                    push_heap(result.begin(), result.end(), cmp);
                }
                else{
                    if((result[0][0] + result[0][1]) >(nums1[i] + nums2[j])){
                        pop_heap(result.begin(), result.end(),cmp);
                        result.pop_back();
                        result.push_back(vector<int>{nums1[i],nums2[j]});
                        push_heap(result.begin(), result.end(), cmp);
                    }
                }
            }
        }
        std::sort(result.begin(),result.end(), cmp);
        return result;
    }
private:
    vector<vector<int>> result;
};