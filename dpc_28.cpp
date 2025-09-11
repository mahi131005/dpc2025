#include<iostream>
#include<queue>
#include<climits>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	
	Node(int x){
		val = x;
		left = right = NULL;
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
    
    bool isSymmetric(){
    	isSymmetric(root);
	}
    
    bool isSymmetric(Node* root){
    	return root == NULL || isSymmetricHelp(root->left, root->right);
	}
	
	bool isSymmetricHelp(Node* left, Node* right){
		if(left==NULL||right==NULL){
			return left==right;
		}
		
		if(left->val!=right->val){
			return false;
		}
		
		return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
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
    cout<<endl;
    
    bool res = tree.isSymmetric();
    
    if(res){
    	cout<<"true";
	}
	else {
		cout<<"false";
	}
    
 	return 0;   
}
