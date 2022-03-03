/*
执行用时：88 ms, 在所有 C++ 提交中击败了89.88% 的用户
内存消耗：40.7 MB, 在所有 C++ 提交中击败了56.80% 的用户
* 使用一个大顶堆存放奇数个的元素， 相当于前半部分都小
* 使用小顶堆存放偶数的元素
* 记得在出现异常时候做出调整
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if((max_heap.size() + min_heap.size())%2 == 0){
            if(min_heap.size()!=0 && min_heap[0] < num){
                min_heap.push_back(num);
                std::push_heap(min_heap.begin(), min_heap.end(), greater<int>());
                num = min_heap[0];
                std::pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
                min_heap.pop_back();
            }
            max_heap.push_back(num);
            std::push_heap(max_heap.begin(), max_heap.end(), less<int>());
        }
        else{
            if(max_heap.size()!=0 && max_heap[0] > num){
                max_heap.push_back(num);
                std::push_heap(max_heap.begin(), max_heap.end(), less<int>());
                num = max_heap[0];
                std::pop_heap(max_heap.begin(), max_heap.end(), less<int>());
                max_heap.pop_back();
            }
            min_heap.push_back(num);
            std::push_heap(min_heap.begin(), min_heap.end(), greater<int>());
        }
    }
    
    double findMedian() {
        if((max_heap.size() + min_heap.size()) % 2) return static_cast<double>(max_heap[0]);
        else return static_cast<double>(max_heap[0] + min_heap[0])/2.0;
    }
private:
    vector<int> max_heap{};
    vector<int> min_heap{};
};