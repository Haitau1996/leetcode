/*
执行用时：4 ms, 在所有 C++ 提交中击败了90.59% 的用户
内存消耗：7.4 MB, 在所有 C++ 提交中击败了86.10% 的用户
*/
class Solution {
public:
    string simplifyPath(string path) {
        std::deque<std::string> buffer;
        size_t i = 0;
        size_t len = path.size();
        bool readPath = false;
        while(i < len){
            if(!readPath && path[i] == '/'){
                readPath = true;
                ++i;
            }
            else if(readPath && path[i] == '/'){
                ++i;
            }
            else{
                int j = 1;
                while((i+j) < len && path[i+j] != '/'){
                    ++j;
                }
                string temp = path.substr(i,j);
                if(temp == "."){
                    ++i;
                    readPath = false; 
                }
                else if(temp == ".."){
                    if(!buffer.empty())
                        buffer.pop_back();
                    i = i + 2;
                    readPath = false;
                }
                else{
                    buffer.push_back(temp);
                    i = i+j;
                    readPath = false;
                }
            }
        }
        string res;
        res.push_back('/');
        for(const auto& i : buffer){
            res += i;
            res.push_back('/');
        }
        if(!buffer.empty())
            res.pop_back();
        return res;
    }
};