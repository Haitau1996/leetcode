// 思路 1： 差分数组， 每次插入一个安排相当于【start, end】 的台阶， start 处+1， end处 -1
// 只需要求得台阶最高的高度
// TODO: 线段树实现
#include <map>

using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {

    }

    int book(int start, int end) {
        int res = 0;
        int curr_val = 0;
        cnt[start]++;
        cnt[end]--;
        for(auto& [_, count]: cnt){
            curr_val += count;
            res = max(res,curr_val);
        }
        return res;
    }
private:
    map<int, int> cnt{};
};
