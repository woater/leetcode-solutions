#include <stdlib.h>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define myMax(x,y) ((x)>(y)?(x):(y))
class Solution {
private:
    // int height(TreeNode* root) {
    //     if (root == NULL)
    //         return 1;
    //     else
    //         return myMax(height(root->left), height(root->right)) + 1;
    // }
    bool distanceTest(int a, int b) {
        int differ = a - b;
        if (differ > 1 || differ < -1) {
            return false;
        }
        else {
            return true;
        }
    }
    int isBalancedWithHeight(TreeNode* root) {
        if (root != NULL) {
            int hl = isBalancedWithHeight(root->left);
            int hr = isBalancedWithHeight(root->right);
            if ((hl != 0) && (hr != 0) && (distanceTest(hl, hr))) {
                return myMax(hl, hr);
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
public:
    // bool isBalanced(TreeNode* root) {
    //     if (root != NULL) 
    //         return isBalanced(root->left) && isBalanced(root->right) && distanceTest(height(root->left), height(root->right));
    //     else {
    //         return true;
    //     }
    // }
    bool isBalanced(TreeNode* root) {
        if (isBalancedWithHeight(root) == 0) {
            return false;
        }
        else {
            return true;
        }
    }
};

//将判断和取高度函数合并，减少递归次数
#define myMax(x,y) ((x)>(y)?(x):(y))
class Solution {
private:
    // int height(TreeNode* root) {
    //     if (root == NULL)
    //         return 1;
    //     else
    //         return myMax(height(root->left), height(root->right)) + 1;
    // }
    bool distanceTest(int a, int b) {
        int differ = a - b;
        if (differ > 1 || differ < -1) {
            return false;
        }
        else {
            return true;
        }
    }
    int isBalancedWithHeight(TreeNode* root) {
        if (root != NULL) {
            int hl = isBalancedWithHeight(root->left);
            int hr = isBalancedWithHeight(root->right);
            //cout << "hl: " << hl << " hr: " << hr << endl;
            if ((hl != 0) && (hr != 0) && (distanceTest(hl, hr))) {
                return myMax(hl, hr)+1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
public:
    // bool isBalanced(TreeNode* root) {
    //     if (root != NULL) 
    //         return isBalanced(root->left) && isBalanced(root->right) && distanceTest(height(root->left), height(root->right));
    //     else {
    //         return true;
    //     }
    // }
    bool isBalanced(TreeNode* root) {
        //cout << isBalancedWithHeight(root) << endl;
        if (isBalancedWithHeight(root) == 0) {
            return false;
        }
        else {
            return true;
        }
    }
};