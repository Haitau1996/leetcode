class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        else if(root->children.size() == 0) return 1;
        int sub_size = 0;
        for(const auto& elem : (root->children)){
            int current_sub = maxDepth(elem);
            if(current_sub > sub_size)
                sub_size = current_sub;
        }
        return 1 + sub_size;
    }
};