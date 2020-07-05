#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
 #define myMin(x,y) ((x)>(y)?(y):(x))
 #define MAX 1000
class Solution {
public:
    int minDepth(TreeNode* root) {
        // if (root != NULL) {
        //     if (root -> left == NULL && root ->right == NULL) {
        //         return 1;
        //     }
        //     else if (root->left != NULL && root->right == NULL){
        //         return minDepth(root->left) + 1;
        //     }
        //     else if (root->right != NULL && root->left == NULL) {
        //         return minDepth(root->right) + 1;
        //     }
        //     else {
        //         return myMin(minDepth(root->left), minDepth(root->right)) + 1;
        //     }
        // }
        // else {
        //     return 0;
        // }
        if (! root ) {
            if (!root->left && ! root->right) {
                return 1;
            }
            else if (root->left && root->right) {
                return myMin(minDepth(root->left), minDepth(root->right)) + 1;
            }
            else if (root->left) {
                return minDepth(root->left) + 1;
            }
            else{
                return minDepth(root->right) + 1;
            }
        }
        else{
            return 0;
        }
    }
};