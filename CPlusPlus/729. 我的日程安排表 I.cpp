// 简单的二叉树的使用

struct MyNode{
    int start;
    int end;
    MyNode* left{nullptr};
    MyNode* right{nullptr};
    MyNode(int s, int e):start(s),end(e){}
};
class MyCalendar {
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        if(root == nullptr){
            root = new MyNode(start, end);
            return true;
        }
        MyNode* cursor = root;
        while(cursor){
            if(cursor->start >= end){
                if(cursor->left){
                    cursor = cursor->left;
                }else{
                    cursor->left = new MyNode(start, end);
                    return true;
                }
            }else if(cursor->end <= start){
                if(cursor->right){
                    cursor = cursor->right;
                }else{
                    cursor->right = new MyNode(start,end);
                    return true;
                }
            }else return false;
        }
        return false;
    }
private:
    MyNode* root{nullptr};
};
