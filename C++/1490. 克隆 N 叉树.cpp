class Solution {
public:
    Node* cloneTree(Node* root) {
        if(root == nullptr) return root;
        Node* result = new Node(root->val);
        for(auto elem : root->children){
            result->children.push_back(cloneTree(elem));
        }
        return result;
    }
};