// 使用指针记下下一个分组的大小的位置
// 分组大小为 1， 则压入一个 3-temp.back(), 
// 否则压入两个
#include <vector>

using namespace std;
class Solution {
public:
    int magicalString(int n) {
        vector<int> temp{1,2,2};
        int curr = 2;
        while(temp.size() < n){
            temp.push_back(3-temp.back());
            if(temp[curr] == 2){
                temp.push_back(temp.back());
            }
            ++curr;
        }
        return count(temp.begin(), temp.begin()+n,1);
    }
};
