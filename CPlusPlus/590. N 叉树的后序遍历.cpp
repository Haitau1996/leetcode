/*
题目简单， 换个递归实现
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        recursion(root);
        return result;
    }
private:
    vector<int> result{};
    void recursion(Node* root){
        if(root == nullptr) return;
        for(auto child : root->children){
            recursion(child);
        }
        result.push_back(root->val);
    }
};