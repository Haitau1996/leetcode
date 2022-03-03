/*
* 暴力解决，根据循环找规律
* 按行打印， 并且维护一个指向当前打印位置的指针
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string result(s.size(),'0');
        int loop_size = 2 * numRows - 2;
        int loop_times = s.size()/ loop_size;
        int loop_remainder = s.size() % loop_size;
        int current = 1;
        for(int i = 1; i <= numRows; ++i){
            for(int j = 1; j <= loop_times; ++j){
                if(i == 1 || i == numRows){
                    result[current-1] = s[(j-1)* loop_size + i-1];
                    ++current;
                }else{
                    result[current-1] = s[(j-1)* loop_size + i-1];
                    ++current;
                    result[current-1] = s[(j-1)* loop_size + 2*numRows - i - 1];
                    ++current;
                }
            }
            if(i <= loop_remainder){
                result[current-1] = s[(loop_times)* (loop_size) + i-1];
                ++current;
            }
            if(2*numRows-i <= loop_remainder && i != numRows){
                result[current-1] = s[loop_times*loop_size + 2 * numRows -i -1];
                ++current;
            }
        }
        return result;
    }
};