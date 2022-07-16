#include <vector>
#include <numeric>
using namespace std;
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
                nume = nume / gcd(nume,demo);
                demo = demo / gcd(nume,demo);
                buffer.emplace_back(vector<int>{nume,demo});
            }
        }
        return buffer.back();
    }
};
