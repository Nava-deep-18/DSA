#include <mybits.h>

// -------------------- TreeNode Structure --------------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

// -------------------- Traversal Functions --------------------

// Recursive traversals
void preorder(TreeNode* root){
    if (root == nullptr) return;
    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root){
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

void postorder(TreeNode* root){
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
}

// Iterative traversals
void preorderUsing1Stack(TreeNode* root){
    if (root == nullptr) return;
    vector<int> preorderVec;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()){
        TreeNode* curr = st.top(); st.pop();
        preorderVec.push_back(curr->val);
        if (curr->right) st.push(curr->right);
        if (curr->left)  st.push(curr->left);
    }
    for (size_t i = 0; i < preorderVec.size(); ++i)
        cout << preorderVec[i] << ' ';
}

void inorderUsing1Stack(TreeNode* root){
    if (root == nullptr) return;
    vector<int> inorderVec;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while (true){
        if (node != nullptr){
            st.push(node);
            node = node->left;
        } else {
            if (st.empty()) break;
            node = st.top(); st.pop();
            inorderVec.push_back(node->val);
            node = node->right;
        }
    }
    for (size_t i = 0; i < inorderVec.size(); ++i)
        cout << inorderVec[i] << ' ';
}

// Postorder using two stacks (iterative)
void postorderUsing2Stacks(TreeNode* root){
    if (root == nullptr) return;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while (!s1.empty()){
        TreeNode* curr = s1.top(); s1.pop();
        s2.push(curr);
        if (curr->left)  s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }
    while (!s2.empty()){
        cout << s2.top()->val << ' ';
        s2.pop();
    }
}

// Level order traversal
void levelOrder(TreeNode* root){
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        vector<int> level;
        size_t sz = q.size();
        for (size_t i = 0; i < sz; ++i){
            TreeNode* curr = q.front(); q.pop();
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            level.push_back(curr->val);
        }
        for (size_t i = 0; i < level.size(); ++i)
            cout << level[i] << ' ';
    }
}

// -------------------- Tree Initialization (Example) --------------------
TreeNode* createSampleTree() {
    /*
         1
       /   \
      2     3
     / \   / \
    4  5  6   7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();

    cout << "pre  : "; preorder(root); cout << '\n';
    cout << "in   : "; inorder(root); cout << '\n';
    cout << "post : "; postorder(root); cout << '\n';

    cout << "pre(it): "; preorderUsing1Stack(root); cout << '\n';
    cout << "in(it) : "; inorderUsing1Stack(root); cout << '\n';
    cout << "post(it-two-stacks): "; postorderUsing2Stacks(root); cout << '\n';

    cout << "level : "; levelOrder(root); cout << '\n';

    return 0;
}
