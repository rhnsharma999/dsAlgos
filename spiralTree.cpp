/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


void printSpiral(Node *root)
{
    if(!root) return;
    Node *s1[10000],*s2[10000];
    int i =-1,j=-1;
    s1[++i] = root;
     //Your code here

     while(i>=0 || j>=0){
         while(i >= 0){
             Node* top = s1[i--];
             cout <<top->data <<" ";
             if(top->right) s2[++j] = top->right;
             if(top->left) s2[++j] = top->left;
         }
         while(j >= 0){
             Node * top = s2[j--];
             cout <<top->data <<" ";
             if(top->left) s1[++i] = top->left;
             if(top->right) s1[++i] = top->right;
         }
     }
}
