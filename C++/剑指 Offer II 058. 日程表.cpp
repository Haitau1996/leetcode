/*
* 自定义的树节点用 MyTreeNode, 因为 TreeNode 在 leetcode 包含的头文件中已经有了
* 时间的区间是左闭右开， 因此是 ">=" 和 “<=”
*/
struct MyTreeNode{
    MyTreeNode* left;
    MyTreeNode* right;
    int beg;
    int end;
    MyTreeNode(int beg,int end):beg(beg),end(end),left(nullptr),right(nullptr){}
};
class MyCalendar {
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        if(cal == nullptr){
            cal = new MyTreeNode(start, end);
            return true;
        }
        MyTreeNode* cursor = cal;
        while(cursor){
            if(end <= cursor->beg){
                if(cursor->left){
                    cursor = cursor->left;
                }
                else{
                    cursor->left = new MyTreeNode(start,end);
                    return true;
                }
            }
            else if(start >= cursor->end){
                if(cursor->right){
                    cursor = cursor->right;
                }
                else{
                    cursor->right = new MyTreeNode(start,end);
                    return true;
                }
            }
            else{
                return false;
            }
        }
        return false;
    }
private:
    MyTreeNode* cal = nullptr;
};