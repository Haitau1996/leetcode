/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.7 MB, 在所有 C++ 提交中击败了5.99% 的用户
*/
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int contIndex = cont.size()-1;
        vector<vector<int>> buffer{};
        for(int i = contIndex; i >= 0; --i){
            if(buffer.empty())  buffer.emplace_back(vector<int>{cont[i],1});
            else{
                auto nume = buffer.back()[1];
                auto demo = buffer.back()[0];
                nume = cont[i] * demo + nume;
                nume = nume / std::gcd(nume,demo);
                demo = demo / std::gcd(nume,demo);
                buffer.emplace_back(vector<int>{nume,demo});
            }
        }
        return buffer.back();
    }
};