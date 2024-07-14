#include <iostream>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string
    string serialize(TreeNode* root) {
        if (!root) return "null,"; // Return "null," if node is nullptr

        // Serialize current node
        string result = to_string(root->val) + ",";
        result += serialize(root->left); // Recursively serialize left subtree
        result += serialize(root->right); // Recursively serialize right subtree

        return result; // Return serialized string
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string token;

        // Split serialized data into tokens based on ','
        while (getline(ss, token, ',')) {
            q.push(token);
        }

        return deserializeHelper(q); // Call helper function to build tree from tokens
    }

private:
    // Helper function to deserialize the tree
    TreeNode* deserializeHelper(queue<string>& q) {
        string token = q.front();
        q.pop();

        if (token == "null") {
            return nullptr; // Return nullptr for "null" token
        }

        // Create new node with integer value of token
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeHelper(q); // Recursively set left child
        node->right = deserializeHelper(q); // Recursively set right child

        return node; // Return current node
    }
};

// Function to print the binary tree (for testing)
void printTree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// Main function for testing the solution
int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Create a codec instance
    Codec codec;

    // Serialize the binary tree
    string serialized = codec.serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    // Deserialize the serialized string back into a binary tree
    TreeNode* deserialized = codec.deserialize(serialized);

    // Print the deserialized binary tree (for verification)
    cout << "Deserialized tree: ";
    printTree(deserialized); // Assume printTree function prints tree in preorder
    cout << endl;

    return 0;
}
