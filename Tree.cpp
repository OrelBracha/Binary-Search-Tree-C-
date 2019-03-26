#include<iostream>
#include "Tree.hpp"
#include <cstdlib>
using namespace std;
using namespace ariel;
    

    

    Tree::node* Tree:: makeEmpty(node* t)
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
    bool Tree:: isExist(node*t, int i)
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

    Tree::node* Tree:: insert(int i, node* t)
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

    Tree::node* Tree::findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    /*Tree::node* Tree:: findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }*/

    Tree::node* Tree:: remove(int i, node* t)
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
        
    
    
    int Tree:: rootInt(node* t)
    {
         return t->data;
    }
    
    int Tree:: getLeftVal(node* t,int i)
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


    int Tree:: getRightVal(node* t,int i)
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
    
    int Tree:: getParentVal(node* t,int i)
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

   

    int Tree:: nodesCountHelper(node* t) 
    {
        if (!t) return 0;
        else return 1 + nodesCountHelper(t->left) + nodesCountHelper(t->right);
    }
    void Tree:: inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    /*Tree::node* Tree:: find(node* t, int x)
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


    Tree::Tree()
    {
        Root = NULL;
    }

    Tree::~Tree()
    {
        Root = makeEmpty(Root);
    }

    void Tree:: insert(int x)
    {
        Root = insert(x, Root);
    }

    void Tree:: remove(int x)
    {
        Root = remove(x, Root);
    }

    void Tree:: print()
    {
        inorder(Root);
        cout << endl;
    }

    
    int Tree:: size()
    {
         int x = nodesCountHelper(Root);
         return x;
    }
    bool Tree:: contains(int x)
    {
       bool result = isExist(Root,x);
       return result;
    }
    int Tree:: root()
    {
       int x = rootInt(Root);
       return x;
    }
    int Tree:: left(int x)
    {
      int result = getLeftVal(Root,x);
      return result;
    }
    int Tree:: right(int x)
    {
      int result = getRightVal(Root,x);
      return result;
    }
    int Tree:: parent(int x)
    {
      int result = getParentVal(Root,x);
      return result;
    }



