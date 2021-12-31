/*
执行用时：20 ms, 在所有 C++ 提交中击败了70.18% 的用户
内存消耗：13.7 MB, 在所有 C++ 提交中击败了7.68% 的用户
*/
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        capacity = size;
    }
    
    double next(int val) {
        if(size < capacity){
            buffer.push_back(val);
            sum += val;
            ++size;
        }
        else{
            buffer.push_back(val);
            sum += val;
            sum -= buffer.front();
            buffer.pop_front();
        }
        return sum/size;
    }
private:
    double sum{};
    int size{};
    deque<int> buffer;
    int capacity;
};