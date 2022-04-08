#include <queue>
#include <deque>
using namespace std;
class MaxQueue {
public:
    MaxQueue() {
    }
    
    int max_value() {
        if(val_que.empty()) return -1;
        return max_que.front();
    }
    
    void push_back(int value) {
        val_que.push(value);
        while(!max_que.empty() && max_que.back() < value){
            max_que.pop_back();
        }
        max_que.push_back(value);
    }
    
    int pop_front() {
        if(val_que.empty()) return -1;
        else{
            if(val_que.front() == max_que.front())
                max_que.pop_front();
            int temp = val_que.front();
            val_que.pop();
            return temp;
        }
    }
private:
    queue<int> val_que{};
    deque<int> max_que{};
};
