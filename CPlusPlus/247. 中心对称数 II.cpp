/*
所谓中心对称数， 我们只需要构造前半部分， 然后根据前半部分生成后半部分。
1. 构造前半部分， 使用**回溯**的方法， 依次像 string 插入可行的字符， 在任意位置都可以插入 1,8,6,9, 除了在首位之外可以插入 0
    * 回溯要注意两点: 一是当长度为 half 的时候记得提前返回， 二是处理完一种情况后记得 pop_back
2. 后半部分就是前半部分反转， 然后将 6 9 呼唤
3. 如果 n 为奇数， 中间插入 0,1,8 中的任意一个即可*/
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        constructHalf(0, n/2);
        vector<string> res;
        for(const auto& elem : halfPart){
            auto revelem = reverseElement(elem);
            if(n%2 == 0){
                res.push_back(elem+revelem);
            }else{
                for(const auto & mid : center){
                    res.push_back(elem + mid +revelem);
                }
            }
        }
        return res;
    }
private:
    vector<char> total{'1', '8','6','9'};
    vector<string> center{"0","1","8"};
    string current{};
    vector<string> halfPart;
    void constructHalf(int cursor,int half){
        if(cursor == half){
            halfPart.push_back(current);
            return;
        }else{
            for(const auto& ca: total){
                current.push_back(ca);
                constructHalf(cursor+1, half);
                current.pop_back();
            }
            if(cursor!=0){
                current.push_back('0');
                constructHalf(cursor+1, half);
                current.pop_back();
            }
        }
    }
    string reverseElement(const string& elem){
        string revelem(elem);
        reverse(revelem.begin(), revelem.end());
        for(size_t i = 0; i < revelem.size(); ++i){
            if(revelem[i] == '6') revelem[i]='9';
            else if(revelem[i] == '9') revelem[i] = '6';
        }
        return revelem;
    }
};
