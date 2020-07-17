// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/validate-binary-search-tree
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <stdlib.h>
#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // transform the problem to be judge if array is ascendeng
    void preorderTraversal(TreeNode* root, vector<int>& vv) {
        if (root != NULL) {
            preorderTraversal(root->left, vv);
            vv.push_back(root->val);
            preorderTraversal(root->right, vv);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> vv;
        preorderTraversal(root, vv);
        for(int i = 1; i < vv.size(); i++) {
            if (vv[i] <= vv[i-1]) {
                return false;
            }
        }
        return true;
    }
};