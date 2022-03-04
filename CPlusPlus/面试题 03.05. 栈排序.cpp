class SortedStack {
public:
    SortedStack() {

    }
    
    void push(int val) {
        if(buffer.empty() ||val <= buffer.top()) buffer.push(val);
        else{
            int temp = buffer.top();
            buffer.pop();
            push(val);
            push(temp);
        }
    }
    
    void pop() {
        if(!buffer.empty()) buffer.pop();
    }
    
    int peek() {
        if(buffer.empty()) return -1;
        return buffer.top();
    }
    
    bool isEmpty() {
        return buffer.empty();
    }
private:
    stack<int> buffer{};
};