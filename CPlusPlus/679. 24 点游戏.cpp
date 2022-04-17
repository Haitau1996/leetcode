#include<vector>
#include<numeric>
#include<cmath>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> in;
        for(const auto& card: cards){
            in.push_back(static_cast<double>(card));
        }
        return doubleJudge(in);
    }
private:
    double ERROR{10e-6};
    bool doubleJudge(vector<double> in){
        if(in.size() == 1){
            if(abs(in.front()-24) < ERROR) return true;
            else return false;
        }
        else{
            for(size_t i = 0; i < in.size(); ++i){
                for(size_t j = 0; j < in.size(); ++j){
                    if(i != j){
                        vector<double> temp(in);
                        temp.erase(temp.begin()+i);
                        if(i<j) temp.erase(temp.begin()+j-1);
                        else temp.erase(temp.begin()+j);
                        auto a = in[i];
                        auto b = in[j];
                        for(auto newItem:{a+b, a-b, a*b}){
                            temp.push_back(newItem);
                            if(doubleJudge(temp)) return true;
                            temp.pop_back();
                        }

                        if(abs(b) > ERROR){
                            temp.push_back(a/b);
                            if(doubleJudge(temp)) return true;
                            temp.pop_back();
                        }
                    }
                }
            }
            return false;
        }
    }
};
