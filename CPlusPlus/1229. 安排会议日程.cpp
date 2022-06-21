/* 
 * 排序+双指针
 */
#include<algorithm>
#include<numeric>
#include <vector>


using std::vector;
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int cur1 = 0;
        int cur2 = 0;
        while(cur1 < slots1.size() && cur2< slots2.size()){
            int s = max(slots1[cur1][0], slots2[cur2][0]);
            int e = min(slots1[cur1][1], slots2[cur2][1]);
            if(e- s >= duration) return vector<int>{s,s+duration};
            else{
                if(slots1[cur1][1] > slots2[cur2][1]){
                    ++cur2;
                }else{
                    ++cur1;
                }
            }
        }
        return vector<int>{};
    }
};
