// 中序遍历 + 归并排序

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res{};
        print_tree(root1, vec1);
        print_tree(root2, vec2);
        int i = 0, j = 0;
        while(i < vec1.size() || j <vec2.size()){
            if(i == vec1.size() || (j != vec2.size() && vec1[i] >= vec2[j])){
                res.push_back(vec2[j]);
                ++j;
            }else if(j == vec2.size() || vec1[i] <= vec2[j]){
                res.push_back(vec1[i]);
                ++i;
            }
        }
        return res;
    }
private:
    vector<int> vec1;
    vector<int> vec2;
    void print_tree(TreeNode* root, vector<int>& position){
        if(root == nullptr) return;
        else{ 
            print_tree(root->left, position);
            position.push_back(root->val);
            print_tree(root->right, position);
        }
    }
};
