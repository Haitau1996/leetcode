#include <map>

using namespace std;
class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        int curr{0};
        int res{0};
        cnt[start]++;
        cnt[end]--;
        for(auto& [_,count]:cnt){
            curr+= count;
            res = max(curr, res);
        }
        if(res <= 2) return true;
        else{
            cnt[start]--;
            cnt[end]++;
            return false;
        }
    }
private:
    map<int, int> cnt{};
};
