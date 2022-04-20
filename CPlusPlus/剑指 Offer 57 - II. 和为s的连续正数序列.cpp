#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int product = target * 2;
        int bound = sqrt(product);
        vector<int> temp;
        vector<vector<int>> res;
        for(int i=2; i <= bound; ++i){
            if(product% i == 0){
                temp.push_back(i);
            }
        }
        for(const auto& x : temp){
            int y = product/x;
            if((x+y)%2){
                int b = (x+y-1)/2;
                int a = y - b;
                if(a != b){
                    vector<int> part{};
                    for(int i = a; i <= b; ++i){
                        part.push_back(i);
                    }
                    res.push_back(part);
                } 
            }           
        }
        sort(res.begin(), res.end());
        return res;
    }
};
