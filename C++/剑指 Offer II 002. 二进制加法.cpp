/*
执行用时：4 ms, 在所有 C++ 提交中击败了61.37% 的用户
内存消耗：6.2 MB, 在所有 C++ 提交中击败了47.83% 的用户
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int digA{0};
        int digB{0};
        string res{};
        int carrier = 0;
        while(i >= 0 || j>=0){
            i<0 ? digA =0: digA = a[i] - '0';
            j<0 ? digB = 0 :digB = b[j] - '0';
            int bitSum = digA + digB + carrier;
            res.push_back('0' + bitSum%2);
            carrier = bitSum/2;
            --i;
            --j;
        }
        if(carrier) res.push_back('1');
        std::reverse(res.begin(), res.end());
        return res;
    }
};