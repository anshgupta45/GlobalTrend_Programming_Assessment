#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN; // Initialize with the smallest possible integer
        maxPathSumHelper(root, maxPath); // Call helper function to compute max path sum
        return maxPath; // Return the maximum path sum found
    }

private:
    // Helper function to recursively compute maximum path sum
    int maxPathSumHelper(TreeNode* node, int& maxPath) {
        if (!node) return 0; // Base case: null node contributes nothing to path sum
        
        // Calculate max path sum in left and right subtrees recursively
        int leftPathSum = max(0, maxPathSumHelper(node->left, maxPath)); // Max path sum ending at left subtree
        int rightPathSum = max(0, maxPathSumHelper(node->right, maxPath)); // Max path sum ending at right subtree
        
        // Calculate max path sum ending at current node
        int maxEndingHere = node->val + max(leftPathSum, rightPathSum); // Include current node
        
        // Calculate max path sum passing through current node
        int maxThroughHere = node->val + leftPathSum + rightPathSum; // Path through current node
        
        // Update global maxPath with the maximum path sum found
        maxPath = max(maxPath, maxThroughHere); // Update maxPath if found a larger path
        
        // Return max path sum ending at current node (for recursion)
        return maxEndingHere;
    }
};


int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    Solution sol;
    cout << "Maximum path sum: " << sol.maxPathSum(root) << endl;
    
    return 0;
}
