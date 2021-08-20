class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        getRight(root);
        getLeft(root);
        connect(root->right);
        connect(root->left);
        return root;
    }
private:
    void getRight(Node* root){
      if(root->right == NULL) return;
      Node* temp = root;
      while(temp->next != NULL){
        if(temp->next->left != NULL ){
          root->right->next = temp->next->left;
          return;
        }
        else if(temp->next->right != NULL ){
          root->right->next = temp->next->right;
          return;
        }
        else temp = temp->next;
      }
      return;
    }
    void getLeft(Node* root){
      if(root->left == NULL) return;
      else if(root -> right != NULL){
        root->left -> next = root->right;
        return;
      }
      Node* temp = root;
      while(temp->next != NULL){
        if(temp->next->left != NULL ){
          root->left->next = temp->next->left;
          return;
        }
        else if(temp->next->right != NULL ){
          root->left->next = temp->next->right;
          return;
        }
        else temp = temp->next;
      }
      return;
      }

};