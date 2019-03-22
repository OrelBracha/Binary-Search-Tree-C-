#include<iostream>
#include "Tree.hpp"
#include <cstdlib>
using namespace std;
using namespace ariel;
    

    

    BST::node* BST:: makeEmpty(node* t)
    {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }
    bool BST:: isExist(node*t, int i)
    {
         if(t==NULL)
         {
          return false;
         }
         if(t->data == i)
         {
          return true;
         }
         if(t->data > i)
         {
         return isExist(t->left,i);
         }
         return isExist(t->right,i);
     }    

    BST::node* BST:: insert(int i, node* t)
    {
        bool existance = isExist(t,i);
        try 
        {
        if(existance)
        { 
        throw i;
        }
        if(t == NULL)
        {
            t = new node;
            t->data = i;
            t->left = t->right = NULL;
        }
        else if(i < t->data)
            t->left = insert(i, t->left);
        else if(i > t->data)
            t->right = insert(i, t->right);
        }
        catch(int ex)
        {
        cout<<"The Value is already exist in the Tree"<<ex<<endl;
        } 

        return t;
        
        
    }

    BST::node* BST::findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    /*BST::node* BST:: findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }*/

    BST::node* BST:: remove(int i, node* t)
    {
        node* temp;
        bool existance = isExist(t,i);
        try
        {
        if(!(existance))
        {
         throw i;
        }
        if(t == NULL)
            return NULL;
        else if(i < t->data)
            t->left = remove(i, t->left);
        else if(i > t->data)
            t->right = remove(i, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        } 
        catch(int ex)
        {
         cout<<"The Value isn't exist in the tree "<<ex<<endl;
        } 
       
        return t;
     }
        
    
    
    int BST:: RootInt(node* t)
    {
         return t->data;
    }
    
    int BST:: getLeftVal(node* t,int i)
    {

                if(t->data==i)
                {

                    return t->left->data;
                }
               else  if(t==NULL)
                {

                    return NULL;
                }

                else if(i<t->data)
                {

                    return getLeftVal(t->left,i);
                }
                else if(i>t->data)
                {

                    return getLeftVal(t->right,i);
                }

    }


    int BST:: getRightVal(node* t,int i)
    {

                if(t->data==i)
                {

                    return t->right->data;
                }
               else  if(t==NULL)
                {

                    return NULL;
                }

                else if(i<t->data)
                {

                    return getRightVal(t->left,i);
                }
                else if(i>t->data)
                {

                    return getRightVal(t->right,i);
                }

    }
    
    int BST:: getParentVal(node* t,int i)
    {

    if(t->left == NULL && t->right == NULL)
       return NULL;

    if( (t->left != NULL && t->left->data == i)
        || (t->right != NULL && t->right->data == i))
       return t->data;

    if(t->data>i)
       return getParentVal(t->left,i);

    if(t->data <i)
       return getParentVal(t->right,i);
    }

   

    int BST:: nodesCountHelper(node* t) 
    {
        if (!t) return 0;
        else return 1 + nodesCountHelper(t->left) + nodesCountHelper(t->right);
    }
    void BST:: inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    /*BST::node* BST:: find(node* t, int x)
    {
        //if(t == NULL)
          //  return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;//
    }*/


    BST::BST()
    {
        root = NULL;
    }

    BST::~BST()
    {
        root = makeEmpty(root);
    }

    void BST:: insert(int x)
    {
        root = insert(x, root);
    }

    void BST:: remove(int x)
    {
        root = remove(x, root);
    }

    void BST:: print()
    {
        inorder(root);
        cout << endl;
    }

    
    int BST:: size()
    {
         int x = nodesCountHelper(root);
         return x;
    }
    bool BST:: contains(int x)
    {
       bool result = isExist(root,x);
       return result;
    }
    int BST:: Root()
    {
       int x = RootInt(root);
       return x;
    }
    int BST:: left(int x)
    {
      int result = getLeftVal(root,x);
      return result;
    }
    int BST:: right(int x)
    {
      int result = getRightVal(root,x);
      return result;
    }
    int BST:: parent(int x)
    {
      int result = getParentVal(root,x);
      return result;
    }



