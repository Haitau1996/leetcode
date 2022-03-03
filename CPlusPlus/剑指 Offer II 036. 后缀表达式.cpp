/*
执行用时：8 ms, 在所有 C++ 提交中击败了86.73% 的用户
内存消耗：11.7 MB, 在所有 C++ 提交中击败了34.36% 的用户
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        stack<int> numStack{};
        for(auto& elem : tokens){
            if(!isOperator(elem)) numStack.push(stoi(elem));
            else{
                int oprand2 = numStack.top();
                numStack.pop();
                int oprand1 = numStack.top();
                numStack.pop();
                if(elem == "+") result = oprand1 + oprand2;
                else if(elem == "-") result = oprand1 - oprand2;
                else if(elem == "*") result = oprand1 * oprand2;
                else result = oprand1/oprand2;
                numStack.push(result);
            }
        }
        return numStack.top();
    }
private:
    bool isOperator(string& str){
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
};