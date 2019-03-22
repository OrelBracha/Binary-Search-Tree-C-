/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::BST emptytree;
  ariel::BST threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.Root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())
  ;
  ariel:: BST empty;
  ariel:: BST standard;
  standard.insert(8);
  standard.insert(6);
  standard.insert(14);
  standard.insert(7);
  standard.insert(4);
  standard.insert(12);
  standard.insert(16);
  badkan::TestCase sap("Binary tree");
  sap
  .CHECK_EQUAL (standard.size(), 7)
  .CHECK_EQUAL (standard.left(14), 12)
  .CHECK_EQUAL (standard.parent(7), 6)
  .CHECK_EQUAL (standard.right(8), 14)
  .CHECK_OK (standard.print())
  .CHECK_EQUAL (standard.contains(2), false)
  .CHECK_THROWS (standard.remove(3))
  .CHECK_THROWS (standard.insert(14))
  .CHECK_EQUAL (standard.Root(), 8)
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
