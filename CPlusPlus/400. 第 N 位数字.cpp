class Solution {
public:
    int findNthDigit(int n) {
        int curr_bits = 1;
        int curr_count = 0;
        long curr_base = 9;
        while(n > (curr_count + curr_base * curr_bits)){
            curr_count = curr_count + curr_base * curr_bits;
            curr_base *= 10;
            ++curr_bits;
        }
        int diff = n - curr_count;
        int dist = (diff-1)/curr_bits;
        int offset = diff% curr_bits;
        if(offset == 0) offset = curr_bits;
        int curr_num = pow(10,curr_bits-1) + dist;
        string temp = to_string(curr_num);
        return stoi(temp.substr(offset-1,1));
    }
};
