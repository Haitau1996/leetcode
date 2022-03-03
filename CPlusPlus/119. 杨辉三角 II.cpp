/*
TODO: 不用递归， 本地修改
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return vector<int>{1};
        else{
            auto prev = getRow(rowIndex - 1);
            vector<int> result{1};
            for(int i = 0; i < prev.size() -1; ++i){
                result.push_back(prev[i]+prev[i+1]);
            }
            result.push_back(1);
            return result;
        }
    }
};