class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> parentMap;
    unordered_set<TreeNode*> visited;

    void buildParentMap(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) {
            parentMap[root->left] = root;
            buildParentMap(root->left);
        }
        if (root->right) {
            parentMap[root->right] = root;
            buildParentMap(root->right);
        }
    }

    int countLeafPairs(TreeNode* root, int distance) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) {
            return countLeafNodesWithinDistance(root, distance, 0);
        }
        return countLeafPairs(root->left, distance) + countLeafPairs(root->right, distance);
    }

    int countLeafNodesWithinDistance(TreeNode* node, int distance, int count) {
        if (node == nullptr || count > distance) return 0;
        if (node->left == nullptr && node->right == nullptr && count > 0 && count <= distance) {
            return 1;
        }

        visited.insert(node);
        int totalPairs = 0;

        if (parentMap.count(node) && visited.find(parentMap[node]) == visited.end()) {
            totalPairs += countLeafNodesWithinDistance(parentMap[node], distance, count + 1);
        }
        if (visited.find(node->left) == visited.end()) {
            totalPairs += countLeafNodesWithinDistance(node->left, distance, count + 1);
        }
        if (visited.find(node->right) == visited.end()) {
            totalPairs += countLeafNodesWithinDistance(node->right, distance, count + 1);
        }

        visited.erase(node);
        return totalPairs;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        parentMap[root] = nullptr;
        buildParentMap(root);
        return countLeafPairs(root, distance) / 2;
    }
};
