#include<iostream>
#include<climits>
#include<queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = NULL;
    }

    void insert(int val) {
        if (val == INT_MIN) return;

        Node* newNode = new Node(val);

        if (!root) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (!temp->right) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    Node* findNode(Node* root, int value) {
        if (!root) return NULL;
        if (root->val == value) return root;

        Node* leftSearch = findNode(root->left, value);
        if (leftSearch) return leftSearch;

        return findNode(root->right, value);
    }

    Node* LowestCommonAncestor(Node* root, Node* p, Node* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }

        Node* left = LowestCommonAncestor(root->left, p, q);
        Node* right = LowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        }
        return left ? left : right;
    }

    int lca(int p, int q) {
        Node* pNode = findNode(root, p);
        Node* qNode = findNode(root, q);

        Node* res = LowestCommonAncestor(root, pNode, qNode);
        return res->val;
    }
};

int main() {
    BinaryTree tree;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values (use -99999 for NULL): ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val == -99999) {
            tree.insert(INT_MIN);
        } else {
            tree.insert(val);
        }
    }

    int p, q;
    cout << "Enter value for p & q: ";
    cin >> p >> q;

    int result = tree.lca(p, q);
    cout << "Output: " << result << endl;
    
    return 0;
}
