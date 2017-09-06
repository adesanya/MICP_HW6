/*_________________________ Assumptions made_____________________
 
 1. Tree is a binary tree
 2. Tree T will never be empty
 3. Tree can be of any size
 4. Function returns bool value
 5. if S is empty function return true
 */

#include<iostream>
using namespace std;

template<typename T>
struct TreeNode
{
    T info;
    TreeNode<T> * left;
    TreeNode<T> * right;
    
    TreeNode(T i,TreeNode<T> *l=NULL,TreeNode<T> *r=NULL)
    :info(i),left(l),right(r)
    {
        
    }
};


template<typename T>
bool contains_sub_tree(TreeNode<T> * s,TreeNode<T> * t)
{
    if(t==nullptr || s==nullptr)
        return true;
    
    if(t->info==s->info)
    {
        bool left=true,right=true;
        if(s->left!=nullptr && t->left!=nullptr)
        {
            left=contains_sub_tree(s->left,t->left);
        }
        if(s->right!=nullptr && t->right!=nullptr)
        {
            right=contains_sub_tree(s->right,t->right);
        }
        return (left && right);
    }
    else
        return false;
    
}

int main()
{
    //_________________________TEST CASES________________________________
    
    //CASE 1 S=NULL and T is a binary tree of size n
    typedef TreeNode<int> newTree;
    TreeNode<int> * s=nullptr;
    TreeNode<int> * t=new TreeNode<int>(7,new newTree(1),new newTree(8));
    cout<<contains_sub_tree<int>(s,t)<<endl;
    
    
    //CASE 2 S and T are the same
    TreeNode<int> * s1=new TreeNode<int>(7,new newTree(1),new newTree(8));
    TreeNode<int> * t1=new TreeNode<int>(7,new newTree(1),new newTree(8));
    cout<<contains_sub_tree<int>(s1,t1)<<endl;
    
    //CASE 3 T is larger than S and contains all its element and structure
    TreeNode<int> * s2=new TreeNode<int>(7,new newTree(1));
    TreeNode<int> * t2=new TreeNode<int>(7,new newTree(1),new newTree(8));
    cout<<contains_sub_tree<int>(s2,t2)<<endl;
    
    //CASE 4 T contains S elements but different structure
    TreeNode<int> * s3=new TreeNode<int>(8,new newTree(1),new newTree(7));
    TreeNode<int> * t3=new TreeNode<int>(7,new newTree(1),new newTree(8));
    cout<<contains_sub_tree<int>(s3,t3)<<endl;
    
    //CASE 5 T does not contain S elements or structure
    TreeNode<int> * s4=new TreeNode<int>(9,new newTree(2),new newTree(17));
    TreeNode<int> * t4=new TreeNode<int>(7,new newTree(1),new newTree(8));
    cout<<contains_sub_tree<int>(s4,t4)<<endl;
    
    
    //___________________________Optimize_______________________________
    /*
     If the size of S and T are given
     return True if size of S > size of T
     
     use function above in any other case (size of S=<T )
     */
    
    
    
    return 0;
};
