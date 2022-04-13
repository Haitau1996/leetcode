#include<vector>
#include<unordered_set>

using namespace std;
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> type_count;
        for(const auto& elem : candyType){
            type_count.insert(elem);
        }
        return min(candyType.size()>>1, type_count.size());
    }
};
