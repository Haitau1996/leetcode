class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> buffer{0};
        for(int i = 1; i <= arr.size(); ++i){
            buffer.push_back(buffer[i-1]+ arr[i-1]);
        }

        int sum = 0;
        for(int i = 1; i <= arr.size(); ++i){
            for(int j = 1; j <= i; j+=2){
                sum += buffer[i] - buffer[i -j];
            }
        }
        return sum;
    }
};