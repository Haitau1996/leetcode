#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<unordered_set>
#include<experimental/numeric>
using namespace std::experimental;
using namespace std;
struct Fraction{
    int up;
    int down;
    Fraction(int _up, int _down):up(_up),down(_down){}
    Fraction(int _up):up(_up),down(1){}
    Fraction():up(0),down(1){}
};
Fraction reduction(Fraction result){
    if(result.down<0){
        result.up=-result.up;
        result.down=-result.down;
    }
    if(result.up==0){
        result.down=1;
    }else{
        int d=gcd(abs(result.up),abs(result.down));
        result.up/=d;
        result.down/=d;
    }
    return result;
}
Fraction add(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.down+f2.up*f1.down;
    result.down=f1.down*f2.down;
    return reduction(result);
}
Fraction minu(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.down-f1.down*f2.up;
    result.down=f1.down*f2.down;
    return reduction(result);
}
Fraction multi(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.up;
    result.down=f1.down*f2.down;
    return reduction(result);
}
Fraction divide(Fraction f1,Fraction f2){
    Fraction result;
    result.up=f1.up*f2.down;
    result.down=f2.up*f2.down;
    return reduction(result);
}
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() <=2) return points.size();
        unordered_map<string, int> count;
        for(int i = 1; i < points.size(); ++i){
            unordered_set<string> temp{};
            for(int j= 0; j < i; ++j){
                auto p1 = points[i];
                auto p2 = points[j];
                if(p1[0] == p2[0]){
                    string k("Inf");
                    string b = to_string(p1[0]);
                    string key = k + "+" + b;
                    auto iter = count.find(key);
                    if(iter == count.end()) {
                        count.emplace(key,2);
                        temp.insert(key);
                    }else if(temp.find(key) == temp.end()){
                        iter->second = iter->second+1;
                        temp.insert(key);
                    }
                }else if(p1[1] == p2[1]){
                    string k("0");
                    string b = to_string(p1[1]);
                    string key = k + "+" + b;
                    auto iter = count.find(key);
                    if(iter == count.end()) {
                        count.emplace(key,2);
                        temp.insert(key);
                    }else if(temp.find(key) == temp.end()){
                        iter->second = iter->second+1;
                        temp.insert(key);
                    }
                }
                else{
                    Fraction kf = reduction(Fraction((p2[1]-p1[1]),(p2[0] -p1[0])));
                    Fraction bf (p1[0]);
                    bf = multi(kf,bf);
                    bf = minu(p1[1], bf);
                    string k = to_string(kf.up) + "/" + to_string(kf.down);
                    string b = to_string(bf.up) + "/" + to_string(bf.down);
                    string key = k + "+" + b;
                    auto iter = count.find(key);
                    if(iter == count.end()) {
                        count.emplace(key,2);
                        temp.insert(key);
                    }else if(temp.find(key) == temp.end()){
                        iter->second = iter->second+1;
                        temp.insert(key);
                    }
                }
            }
        }
        int result = 0;
        for(auto iter = count.begin(); iter!=count.end(); ++iter){
            if(iter->second > result)
                result = iter->second;
        }
        return result;
    }
};
