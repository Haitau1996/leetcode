/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.7 MB, 在所有 C++ 提交中击败了74.06% 的用户
*/
#include<stack>
using std::stack;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int temp = outStack.top();
        outStack.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return  inStack.empty() &&
                outStack.empty();
    }
private:
    stack<int> inStack;
    stack<int> outStack;
};