/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<vector>
class Solution { //非递归实现
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        else {} //do nothing
        std::vector<int> vl, vr;//使用两个vector保存左右子树节点值
        this->LeftInOrderTraversal(root->left, vl);//储存左子树节点
        this->RightInOrderTraversal(root->right, vr);//储存右子树节点

        if (vl.size() != vr.size()) { //若左右子树节点数不同，则 返回False
            return false;
        }
        else {} // do nothing

        while ((!vl.empty()) && (!vr.empty())) {   //逐个比较对应节点
            if (vl.back() != vr.back()) {
                return false;
            }
            else {
                vl.pop_back();
                vr.pop_back();
            }
        }
        if (vl.empty() && vr.empty() ) { //检查完成，返回True
            return true;
        }
        else {
            return false;
        }

    }
    void LeftInOrderTraversal(TreeNode* root, std::vector<int>& vi){
        if (root == NULL) {
            vi.push_back(-1);//此处使用-1作为空节点，假设了元素均大于0，可能会引入错误
            return;
        }
        else {
            vi.push_back(root->val);
            this->LeftInOrderTraversal(root->left, vi);
            this->LeftInOrderTraversal(root->right, vi);
        }
    }
    void RightInOrderTraversal(TreeNode* root, std::vector<int>& vi){
        if (root == NULL) {
            vi.push_back(-1);
            return;
        }
        else {
            vi.push_back(root->val);
            this->RightInOrderTraversal(root->right, vi);
            this->RightInOrderTraversal(root->left, vi);
        }
    }
};

//递归实现
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        else {
            return subIsSymmetric(root->left, root->right);
        }
    }
    bool subIsSymmetric(const TreeNode* lt, const TreeNode* rt) {
        if ((lt != NULL) && (rt != NULL)) {
            return (lt->val == rt->val) && subIsSymmetric(lt->left, rt->right) && subIsSymmetric (lt->right, rt->left);
        }
        else if (lt != rt) {
            return false;
        }
        else {
            return true;
        }
    }
};