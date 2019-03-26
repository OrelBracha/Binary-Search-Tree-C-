#include <iostream>
//#include <Tree.cpp>//
using namespace std;
namespace ariel
{

  class Tree
 {
   struct node
   {
      int data;
      node* left;
      node* right;
   };
   private:
   
   
   
   node* makeEmpty(node* t);

   node* insert(int i, node* t);
   
   node* remove(int i, node* t);

   int rootInt(node* t);

   int getLeftVal(node* t,int i);

   int getRightVal(node* t,int i);

   int getParentVal(node* t,int i);

   bool isExist(node*t, int i);
   
   int nodesCountHelper(node* t);

   void inorder(node* t);
   
   node* findMin(node* t);

   public:
    node* Root;
   
    Tree();  

   ~Tree();
   
   void insert(int x);
   
   void remove(int x);

   void print();
   
   int size();

   bool contains(int x);
   
   int root();
   
   int right(int x);

   int left(int x);

   int parent(int x);
  };
}

