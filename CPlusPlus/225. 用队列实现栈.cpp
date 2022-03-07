/*
对于一个队列， 想要知道队尾的元素的值(就是 stack的 top), 只能先记录当前的头节点值 last， 然后不断 pop 并将结果放入备用队列中, 直到队列为空的时候， 记录的值就是需要的值
1. 如过是 pop, 那么 last 不需要压入备用队列中
2. 如果是 top, 则需要将 last 压入备用队列

这个模拟过程结束之后， 需要交换主队列和备用队列
*/
class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int last = in.front();
        in.pop();
        while(!in.empty()){
            helper.push(last);
            last = in.front();
            in.pop();        
        }
        swap(in,helper);
        return last;
    }
    
    int top() {
        int last;
        while(!in.empty()){
            last = in.front();
            in.pop();
            helper.push(last);
        }
        swap(in, helper);
        return last;
    }
    
    bool empty() {
        return in.empty();
    }
private:
    queue<int> in{};
    queue<int> helper{};
};