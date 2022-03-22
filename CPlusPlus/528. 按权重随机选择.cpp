#include<vector>
#include<cstdlib>
using namespace std;
class Solution {
public:
    Solution(vector<int>& w) {
        for(const auto& elem : w){
            if(buffer.empty()) buffer.push_back(elem);
            else buffer.push_back(elem + buffer.back());
        }
    }
    
    int pickIndex() {
        int index = rand()%buffer.back() + 1;
        for(int i = 0; i < buffer.size(); ++i){
            if(index <= buffer[i])
                return i;
        }
        return buffer.size()-1;
    }
private:
    vector<int> buffer;
};
