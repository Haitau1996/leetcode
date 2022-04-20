/*
  我们使用一个树结构模拟文件夹， 树中的节点包括几个信息： 当前层级， 当前长度， 子节点数组和父节点。
遍历的过程中位置一个记录字符串位置的光标 cursor:
    1. 先从 cursor 开始扫描 '\t', 记录当前层级
    2. 然后使用一个 high 记录当前目录终止的位置， high - cursor 即为当前文件的长度， 同时使用一个 Bool 变量判断当前是文件还是文件夹
    3. 如果 parent 的层级大于等于当前， 则在树中沿着父节点遍历， 直到找到恰好比当前小 1 的层级
        1. 找到后将当前构建的节点压入 parent 子节点数组
        2. 将当前节点的父节点设置为 parent
        3. 如果总长度大于 res并且节点为文件, 更新 res 值
    4. 将cursor 移动到 high+1 处， 继续遍历
    */

#include<vector>
#include<string>

using namespace std;
struct MyNode{
    int lev;
    int len;
    MyNode* parent{};
    vector<MyNode*> children{};
    MyNode(int _lev, int _len):lev(_lev),len(_len){}
};
typedef MyNode* Tree;
class Solution {
public:
    Solution(){
        root = new MyNode(-1, 0);
    }
    int lengthLongestPath(string input) {
        construct(root, input,0);
        return res;
    }
private:
    Tree root;
    int res{};
    void construct(Tree parent, const string& input, int cursor){
        if(cursor >= input.size()) return;
        int level = 0;
        while(cursor < input.size() && input[cursor] == '\t'){
            ++level;
            ++cursor;
        }
        int high = cursor;
        bool isFile(false);
        while(high < input.size() && input[high]!='\n'){
            if(input[high] == '.') isFile = true;
            ++high;
        }
        int loacl_len = high - cursor;
        while(parent->lev >= level){
            parent = parent->parent;
        }
        int parent_len = (parent->lev == -1 ? 0 : 1) + parent->len;
        loacl_len += parent_len;
        if(loacl_len > res && isFile) res = loacl_len;
        MyNode* temp = new MyNode(level, loacl_len);
        temp->parent = parent;
        parent->children.push_back(temp);
        construct(temp, input, high+1);
    }
};
