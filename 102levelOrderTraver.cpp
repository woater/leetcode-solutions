#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return vector<vector<int>>();
        queue<TreeNode*> qn;
        vector<vector<int>> ans;
        qn.push(root);
        while (!qn.empty()) {
            int count = qn.size();
            vector<int> row;
            while (count--) {
                TreeNode* temp = qn.front();
                qn.pop();
                row.push_back(temp->val);
                if (temp->left)
                    qn.push(temp->left);
                if (temp->right)
                    qn.push(temp->right);
            }
            ans.push_back(row);
        }
        return ans;
    }
};