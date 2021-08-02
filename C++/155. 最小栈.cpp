/*
执行用时：20 ms, 在所有 C++ 提交中击败了92.51% 的用户
内存消耗：15.9 MB, 在所有 C++ 提交中击败了84.43% 的用户
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        if(minStack.empty() || val <= minStack.top())
            minStack.push(val);
        normalStack.push(val);
    }
    
    void pop() {
        if(normalStack.top() == minStack.top())
            minStack.pop();
        normalStack.pop();
    }
    
    int top() {
        return normalStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
private:
    stack<int> normalStack;
    stack<int> minStack;
};
