/*
* 使用 getline 和分割符号可以很方便地提取字符串中的信息
* stringstream 中的 stream 打字的时候别漏了 r
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = split(version1);
        auto v2 = split(version2);
        int cur1 = 0;
        int cur2 = 0;
        while(cur1 < v1.size() && cur2 < v2.size()){
            if(v1[cur1] < v2[cur2]) return -1;
            else if(v1[cur1] > v2[cur2]) return 1;
            else{
                ++cur1;
                ++cur2;
            }
        }
        while(cur1 < v1.size()){
            if(v1[cur1] == 0){
                ++cur1;
            }
            else break;
        }
        while(cur2 < v2.size()){
            if(v2[cur2] == 0){
                ++cur2;
            }
            else break;
        }
        if(cur1 == v1.size() && cur2 == v2.size()) return 0;
        else if(cur1 < v1.size()) return 1;
        else return -1;
    }
private:
    vector<int> split(string& input){
        vector<int> result{};
        const char delim = '.';
        stringstream ss(input);
        string temp;
        while(getline(ss,temp,delim)){
            result.push_back(stoi(temp));
        }
        return result;
    }
};