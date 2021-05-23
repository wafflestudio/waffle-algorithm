// 32ms, 29MB
// serialize: O(#nodes)
// deserialize: O(length of string)
// 대충 둘이 시간복잡도는 같을듯
#include <string>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        string result = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (not q.empty()) {
            TreeNode *tmpNode = q.front();
            q.pop();
            if (tmpNode == nullptr) {
                result += "n";
            }
            else {
                result += to_string(tmpNode->val);
                q.push(tmpNode->left);
                q.push(tmpNode->right);
            }
            result += " ";
        }
        
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        queue<TreeNode*> q;
        
        int data_len = data.size();
        string temp_digit = "";
        int idx = 0;
        while(isdigit(data[idx]) || data[idx] == '-') {
            temp_digit += data[idx++];
        }
        TreeNode* root = new TreeNode(atoi(temp_digit.c_str()));
        q.push(root);
        
        int child_count = 0;
        TreeNode *currNode;
        
        while (not q.empty()) {
            if (data[idx] == ' ') {
                ++idx;
                continue;
            }
            
            if (child_count == 0) {
                currNode = q.front();
                q.pop();
            }
            if (not currNode) continue;
            
            if (isdigit(data[idx]) || data[idx] == '-') {
                string temp_digit = "";
                while(isdigit(data[idx]) || data[idx] == '-') {
                    temp_digit += data[idx++];
                }
                TreeNode* tmpNode = new TreeNode(atoi(temp_digit.c_str()));
                if (child_count == 0) {
                    currNode->left = tmpNode;
                    child_count = 1;
                }
                else {
                    currNode->right = tmpNode;
                    child_count = 0;
                }
                q.push(tmpNode);
            }
            else if (data[idx] == 'n') {
                if (child_count == 0) {
                    currNode->left = nullptr;
                    child_count = 1;
                }
                else {
                    currNode->right = nullptr;
                    child_count = 0;
                }
                q.push(nullptr);
                idx += 2;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));