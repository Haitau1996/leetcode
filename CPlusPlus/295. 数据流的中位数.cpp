class MedianFinder {
public:
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        if(count%2 == 0) {
            ++count;
            if(second.empty() || num >= second.top()){
                first.push(num);
            }
            else{
                int temp = second.top();
                second.pop();
                second.push(num);
                first.push(temp);
            }
        }
        else{
            ++count;
            if(num <= first.top()){
                second.push(num);
            }else{
                int temp = first.top();
                first.pop();
                first.push(num);
                second.push(temp);
            }
        }
    }
    
    double findMedian() {
        if(count%2 == 0) return double(first.top() + second.top())/2.0;
        else return static_cast<double>(first.top());
    }
private:
    int count;
    priority_queue<int,vector<int>,std::greater<int>> first;
    priority_queue<int,vector<int>,std::less<int>> second;
};