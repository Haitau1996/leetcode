/*
暴力递归， 超时了
//todo:解决超时问题
*/
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        dfs(num,0,0,target);
        return result;
    }
private:
    vector<string> selected{};
    vector<string> result{};
    void dfs(string& num, int low, int high, int target){
        if(low == num.size() && my_eval_fun(selected) == target){
            result.push_back(get_result(selected));
            return;
        }
        else if(low >= num.size() || high >= num.size()){
            return;
        }
        if(high > low && num[low] == '0') return;
        // case 1: select current 
        string now = num.substr(low, high-low+1);
       if(high != num.size()-1){
            selected.push_back(now);
            selected.push_back("+");
            dfs(num,high+1,high+1,target);
            selected.pop_back();

            // sub case 2: subtraction
            selected.push_back("-");
            dfs(num,high+1, high+1,target);
            selected.pop_back();

            // sub case 3: multiply
            selected.push_back("*");
            dfs(num, high+1, high+1,target);
            selected.pop_back();
            selected.pop_back();
       }else{
            selected.push_back(now);
            dfs(num,high+1,high+1,target);
            selected.pop_back();
       }
        // case 2: igonre current 
        dfs(num,low, high+1,target);
    }
    string get_result(vector<string>& in){
        string s;
        for(const auto&peice : in){
            s+= peice;
        }
        return s;
    }
    int my_eval_fun(vector<string> selected){
        stack<int> operand{};
        stack<string> opr{};
        for(int i = 0; i < selected.size(); ++i){
            if(selected[i]!= "+" && selected[i]!="-" && selected[i]!= "*"){
                operand.push(stoi(selected[i]));
            }
            else if(opr.empty()){
                opr.push(selected[i]);
            }
            else if(opr.top() == "*"){
                int second = operand.top();
                operand.pop();
                int first = operand.top();
                operand.pop();
                operand.push(first * second);
                opr.pop();
                opr.push(selected[i]);
            }else if(selected[i] == "*"){
                opr.push(selected[i]);
            }
            else{
                auto op = opr.top();
                int second = operand.top();
                operand.pop();
                int first = operand.top();
                operand.pop();
                int temp;
                if(op == "+"){
                    temp = first + second;
                }else{
                    temp = first - second;
                }
                operand.push(temp);
                opr.pop();
                opr.push(selected[i]);
            }
        }
        while(!opr.empty()){
            int second = operand.top();
            operand.pop();
            int first = operand.top();
            operand.pop();
            auto op = opr.top();
            int temp;
            if(op == "+"){
                temp = first + second;
            }else if(op == "-"){
                temp = first - second;
            }else{
                temp = first * second;
            }
            operand.push(temp);
            opr.pop();
        }
        return operand.top();
    }
};