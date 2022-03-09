class Solution {
public:
    string toHex(int num) {
        string result{};
        unsigned num_u = num;         
        vector<char> buffer{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        while(num_u){
            int index = num_u & 0xf;
            result.push_back(buffer[index]);
            num_u >>= 4;
        }
        reverse(result.begin(), result.end());
        if(result.size() == 0) return "0";
        return result;
    }
};