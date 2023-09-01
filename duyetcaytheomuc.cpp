#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left, *right;
    node(int x)
    {
        val = x;
        left = right = NULL;
    }
};
void levelorder(node* root)
{
    // if(root == NULL) return;
    // cout << root->val << " ";
    // levelorder(root->left);
    // levelorder(root->right);
    queue<node* > Q;
    Q.push(root);
    while(!Q.empty()){
        node* nd = Q.front(); Q.pop();
        cout << nd->val << " ";
        if(nd->left != NULL) Q.push(nd->left);
        if(nd->right != NULL) Q.push(nd->right);
    }

}
set<int> st;
void kt(node* root)
{
    queue<pair<node* ,int>> Q;
    Q.push({root, 1});
    while(!Q.empty()){
        pair<node* ,int> nd = Q.front(); Q.pop();
        if(nd.first->left == NULL and nd.first->right == NULL) st.insert(nd.second);
        nd.second++;
        if(nd.first->left != NULL) Q.push({nd.first->left, nd.second});
        if(nd.first->right != NULL) Q.push({nd.first->right, nd.second});
    }
}
bool isperfect(node* root){
    if(!root) return true;
    if(!root->left and !root->right) return true;
    node *r, *l;
    r = root->left;
    l = root->right;
    if(r&&l){
        if(isperfect(l)&&isperfect(r)) return true;
    }
    return false;
}

void insert(node *root, int a, int b, char c)
{
    if(root == NULL) return;
    if(root->val == a){
        if(c == 'L') root->left = new node(b);
        if(c == 'R') root->right = new node(b);
    }
    else{
        insert(root->left, a, b, c);
        insert(root->right,a, b, c);
    }
}
int isindentical(node* root, node* root1)
{
    if(root==NULL and root1==NULL) return 1;
    if(root&&root1){
        if(isindentical(root->left, root1->left)&&(root->val==root1->val)&&isindentical(root->right, root1->right))
        {
            return 1;
        }
        return 0;
    }
    return 0;
}
node* create(node* root=NULL)
{
    int n;
    cin >> n;
    int a, b;
    char c;
    for(int i = 0;i < n; i++){
        cin >> a >> b >> c;
        if(root == NULL) {
            root = new node(a);
            if(c == 'L') root->left = new node(b);
            if(c == 'R') root->right = new node(b);
        }
        else{
            insert(root, a, b, c);
        }
    } 
    return root;
}
int sum;
void sum_node_right(node* root)
{
    if(root == NULL) return;
    // if(root->left == NULL and root->right == NULL) return;
    if(root->right != NULL and root->right->left == NULL and root->right->right == NULL) sum += root->right->val;
    sum_node_right(root->left);
    sum_node_right(root->right);
}
int main(){
    int t;
    cin>> t;
    while(t--){
        node* root = create();
        sum = 0;
        if(root->right == NULL ) sum = root->val;
        else{

        sum_node_right(root);
        }

        cout << sum << endl;
        // node *root1 = create();
        // st.clear();
        // kt(root);
        // string ans = (isperfect(root)&&(st.size()==1)) ? "Yes" : "No";
        // cout << ans <<endl;
        // cout << isindentical(root, root1) << endl;

    }
}