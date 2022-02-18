class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()) return "0";
        int removed = 0;
        for(int i = 0; i < num.size(); ){
            if(removed == k) break;
            if(to_remove.empty() || num[i] >= num[to_remove.top()]){
                to_remove.push(i);
                ++i;
            }
            else{
                num[to_remove.top()] = 'x';
                ++removed;
                to_remove.pop();
            }
        }
        while(removed < k){
            num[to_remove.top()] = 'x';
            ++removed;
            to_remove.pop();
        }
        auto new_end = std::remove(num.begin(),num.end(), 'x');
        num.erase(new_end,num.end());
        int zero_count{};
        for(int i = 0; i < num.size(); ++i){
            if(num[i] != '0') break;
            else ++zero_count;
        }
        if(zero_count == num.size()) return "0";
        return num.substr(zero_count);
    }
private:
    stack<int> to_remove{};
};