/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：14.5 MB, 在所有 C++ 提交中击败了96.46% 的用户

这里是使用一个栈去模拟行为， 我们需要注意在模拟的时候判断终止条件
    1. 输入栈全输入进去了， 但是栈顶和输出不匹配
    2. 输出栈的指针也到了最后一个元素的后一位
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        size_t push_cursor{0};
        size_t pop_cursor{0};
        while(true){
            if(pop_cursor == popped.size()) return true;
            else if(push_cursor == pushed.size() && simulater.top() != popped[pop_cursor])
                return false;
            else if(simulater.empty() || popped[pop_cursor] != simulater.top()){
                simulater.push(pushed[push_cursor]);
                ++push_cursor;
            }
            else if(popped[pop_cursor] == simulater.top()){
                ++pop_cursor;
                simulater.pop();
            }
        }
    }
private:
    std::stack<int> simulater{};
};
