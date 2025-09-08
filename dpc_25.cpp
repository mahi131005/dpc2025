#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() : root(NULL) {}

    void buildLevelOrder(int arr[], int n) {
        if (n == 0 || arr[0] == -99999) {
            root = NULL;
            return;
        }

        root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < n) {
            Node* current = q.front();
            q.pop();

            if (i < n && arr[i] != -99999) {
                current->left = new Node(arr[i]);
                q.push(current->left);
            }
            i++;

            if (i < n && arr[i] != -99999) {
                current->right = new Node(arr[i]);
                q.push(current->right);
            }
            i++;
        }
    }

    void checkAndPrintBST() {
        bool res = isValidBST(root, LLONG_MIN, LLONG_MAX);
        cout << (res ? "true" : "false") << endl;
    }

private:
    bool isValidBST(Node* node, long long minVal, long long maxVal) {
        if (node == NULL) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return isValidBST(node->left, minVal, node->val) &&
               isValidBST(node->right, node->val, maxVal);
    }
};

int main() {
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements (-99999 for null): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    BinaryTree tree;
    tree.buildLevelOrder(arr, n);
    tree.checkAndPrintBST();

    return 0;
}
