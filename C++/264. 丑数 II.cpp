/* 
 * 需要注意可能出现重叠的情况
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ptr(3,0);
        vector<int> result{1};
        while(result.size() < n){
            auto min_val = std::min({2 * result[ptr[0]], 3 * result[ptr[1]], 5* result[ptr[2]]});
            result.push_back(min_val);
            if(min_val == 2 * result[ptr[0]]) ++ptr[0];
            if(min_val == 3 * result[ptr[1]]) ++ptr[1];
            if(min_val == 5 * result[ptr[2]]) ++ptr[2];
        }
        return result.back();
    }
};