/*
执行用时：16 ms, 在所有 C++ 提交中击败了91.31% 的用户
内存消耗：14.5 MB, 在所有 C++ 提交中击败了99.06% 的用户
*/
/* 这个题目需要注意到两点
* min 可能有重合
* minStack 可能为空需要及时检查
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(minStack.empty() || x <= minStack.top())
            minStack.push(x);
        mainStack.push(x);
    }
    
    void pop() {
        if(!minStack.empty() && minStack.top() == mainStack.top())
            minStack.pop();
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;
};