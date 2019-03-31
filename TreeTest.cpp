/**
 * Examples of automatic tests for the exercise on binary standards.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  ariel::Tree first;
  ariel::Tree standard;//Our standard for checking
  ariel::Tree complex;
  
  int array[]={21,30,5,7,14,4,25,26,13,10};
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  badkan::TestCase tc("Binary Tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())
  .CHECK_OK (first.insert(8))
  .CHECK_OK (first.insert(6))
  .CHECK_OK (first.insert(14))
  .CHECK_OK (first.insert(7))
  .CHECK_OK (first.insert(4))
  .CHECK_OK (first.insert(12))
  .CHECK_OK (first.insert(16))
  .CHECK_EQUAL (first.size(), 7)
  .CHECK_EQUAL (first.left(14), 12)
  .CHECK_EQUAL (first.parent(7), 6)
  .CHECK_EQUAL (first.right(8), 14)
  .CHECK_OK (first.print())
  .CHECK_EQUAL (first.contains(2), false)
  .CHECK_THROWS (first.remove(3))
  .CHECK_THROWS (first.insert(14))
  .CHECK_EQUAL (first.root(), 8)
  .CHECK_OK (first.print())
  .CHECK_EQUAL (standard.size(), 0)
  .CHECK_OK    (standard.insert(7))
  .CHECK_OK    (standard.insert(3))
  .CHECK_EQUAL (standard.size(), 2)
  .CHECK_EQUAL (standard.root(), 7)
  .CHECK_EQUAL (standard.left(7), 3)
  .CHECK_THROWS (standard.right(7))
  .CHECK_OK    (standard.insert(8))
  .CHECK_EQUAL (standard.right(7), 8)
  .CHECK_EQUAL (standard.contains(8), true)
  .CHECK_EQUAL (standard.contains(7), true)
  .CHECK_EQUAL (standard.contains(3), true)
  .CHECK_EQUAL (standard.contains(0), false)
  .CHECK_EQUAL (standard.size(), 3) 
  .CHECK_EQUAL (standard.parent(8), 7)
  .CHECK_EQUAL (standard.parent(3), 7)
  .CHECK_OK    (standard.remove(7))
  .CHECK_OK    (standard.remove(3))  
  .CHECK_OK    (standard.remove(8))
  .CHECK_EQUAL (standard.size(), 0)
  .CHECK_EQUAL (complex.size(), 0)
  .CHECK_OK    (standard.insert(7))
  .CHECK_OK    (standard.insert(3))
  .CHECK_EQUAL (standard.size(), 2)
  .CHECK_EQUAL (standard.root(), 7)
  .CHECK_EQUAL (standard.left(7), 3)
  .CHECK_THROWS (standard.right(7))
  .CHECK_OK    (standard.insert(8))
  .CHECK_EQUAL (standard.right(7), 8)
  .CHECK_EQUAL (standard.contains(8), true)
  .CHECK_EQUAL (standard.contains(7), true)
  .CHECK_EQUAL (standard.contains(3), true)
  .CHECK_EQUAL (standard.contains(0), false)
  .CHECK_EQUAL (standard.size(), 3) 
  .CHECK_EQUAL (standard.parent(8), 7)
  .CHECK_EQUAL (standard.parent(3), 7)
  .CHECK_OK    (standard.remove(7))
  .CHECK_OK    (standard.remove(3))  
  .CHECK_OK    (standard.remove(8))
  .CHECK_EQUAL (standard.size(), 0)
  .CHECK_EQUAL (complex.size(), 0)
 .CHECK_OK    (complex.insert(array[0]))
 .CHECK_EQUAL (complex.contains(array[0]), true)
 .CHECK_EQUAL (complex.size(), 1)
 .CHECK_OK    (complex.insert(array[1]))
 .CHECK_EQUAL (complex.contains(array[1]), true)
 .CHECK_EQUAL (complex.size(), 2)
 .CHECK_OK    (complex.insert(array[2]))
 .CHECK_EQUAL (complex.contains(array[2]), true)
 .CHECK_EQUAL (complex.size(), 3)
 .CHECK_OK    (complex.insert(array[3]))
 .CHECK_EQUAL (complex.contains(array[3]), true)
.CHECK_EQUAL (complex.size(), 4)
 .CHECK_OK    (complex.insert(array[4]))
 .CHECK_EQUAL (complex.contains(array[4]), true)
.CHECK_EQUAL (complex.size(), 5)
 .CHECK_OK    (complex.insert(array[5]))
 .CHECK_EQUAL (complex.contains(array[5]), true)
.CHECK_EQUAL (complex.size(), 6)
 .CHECK_OK    (complex.insert(array[6]))
 .CHECK_EQUAL (complex.contains(array[6]), true)
.CHECK_EQUAL (complex.size(), 7)
 .CHECK_OK    (complex.insert(array[7]))
 .CHECK_EQUAL (complex.contains(array[7]), true)
.CHECK_EQUAL (complex.size(), 8)
 .CHECK_OK    (complex.insert(array[8]))
 .CHECK_EQUAL (complex.contains(array[8]), true)
.CHECK_EQUAL (complex.size(), 9)
 .CHECK_OK    (complex.insert(array[9]))
 .CHECK_EQUAL (complex.contains(array[9]), true)
.CHECK_EQUAL (complex.parent(30), 21)
 .CHECK_EQUAL (complex.parent(5), 21)
 .CHECK_EQUAL (complex.parent(4), 5)
 .CHECK_EQUAL (complex.parent(7), 5)
 .CHECK_EQUAL (complex.parent(14), 7)
 .CHECK_EQUAL (complex.parent(13), 14)
 .CHECK_EQUAL (complex.parent(10), 13)
 .CHECK_EQUAL (complex.parent(26), 25)
 .CHECK_EQUAL (complex.parent(25), 30)
.CHECK_EQUAL (complex.right(21), 30)
 .CHECK_EQUAL (complex.right(5), 7)
 .CHECK_EQUAL (complex.right(7), 14)
 .CHECK_EQUAL (complex.right(25), 26)
.CHECK_EQUAL (complex.left(21), 5)
 .CHECK_EQUAL (complex.left(5), 4)
 .CHECK_EQUAL (complex.left(30), 25)
 .CHECK_EQUAL (complex.left(14), 13)
 .CHECK_EQUAL (complex.left(13), 10)
.CHECK_EQUAL (complex.size(), 10)
.CHECK_EQUAL (complex.root(), 21)
.CHECK_OK    (complex.remove(21))
.CHECK_EQUAL (complex.root(), 14)
.CHECK_EQUAL (complex.size(), 9)
.CHECK_EQUAL (complex.left(14), 5)
.CHECK_EQUAL (complex.right(14), 30)
.CHECK_EQUAL (complex.contains(21), false)
.CHECK_OK    (complex.remove(14))
.CHECK_EQUAL (complex.contains(14), false)
.CHECK_EQUAL (complex.root(), 13)
.CHECK_EQUAL (complex.size(), 8)
.CHECK_EQUAL (complex.left(13), 5)
.CHECK_EQUAL (complex.right(13), 30)
.CHECK_OK    (complex.remove(13))
.CHECK_EQUAL (complex.contains(13), false)
.CHECK_EQUAL (complex.root(), 10)
.CHECK_EQUAL (complex.size(), 7)
.CHECK_EQUAL (complex.left(10), 5)
.CHECK_EQUAL (complex.right(10), 30)
.CHECK_OK    (complex.remove(5))
.CHECK_EQUAL (complex.contains(5), false)
.CHECK_EQUAL (complex.root(), 10)
.CHECK_EQUAL (complex.size(), 6)
.CHECK_EQUAL (complex.left(10), 4)
.CHECK_EQUAL (complex.right(4), 7)
.CHECK_OK    (complex.remove(10))
.CHECK_EQUAL (complex.contains(10), false)
.CHECK_EQUAL (complex.root(), 7)
.CHECK_EQUAL (complex.size(), 5)
.CHECK_EQUAL (complex.left(7), 4)
.CHECK_EQUAL (complex.right(7), 30)

.CHECK_OK    (complex.remove(7))
.CHECK_EQUAL (complex.contains(7), false)
.CHECK_EQUAL (complex.root(), 4)
.CHECK_EQUAL (complex.size(), 4)
.CHECK_EQUAL (complex.right(4), 30)

.CHECK_OK    (complex.remove(26))
.CHECK_EQUAL (complex.contains(26), false)
.CHECK_EQUAL (complex.root(), 4)
.CHECK_EQUAL (complex.size(), 3)
.CHECK_EQUAL (complex.right(4), 30)

.CHECK_EQUAL (complex.parent(30), 4)

.CHECK_OK    (complex.remove(30))
.CHECK_EQUAL (complex.contains(30), false)
.CHECK_EQUAL (complex.root(), 4)
.CHECK_EQUAL (complex.size(), 2)
.CHECK_EQUAL (complex.right(4), 25)

.CHECK_EQUAL (complex.parent(25), 4)

.CHECK_OK    (complex.remove(4))
.CHECK_EQUAL (complex.contains(4), false)
.CHECK_EQUAL (complex.root(), 25)
.CHECK_EQUAL (complex.size(), 1)

.CHECK_OK    (complex.remove(25))
.CHECK_EQUAL (complex.contains(25), false)
.CHECK_EQUAL (complex.size(), 0)



.CHECK_EQUAL (complex.size(), 0)
.CHECK_OK    (complex.insert(array[0]))
.CHECK_EQUAL (complex.contains(array[0]), true)


.CHECK_EQUAL (complex.size(), 1)
.CHECK_OK    (complex.insert(array[1]))
.CHECK_EQUAL (complex.contains(array[1]), true)


.CHECK_EQUAL (complex.size(), 2)
.CHECK_OK    (complex.insert(array[2]))
.CHECK_EQUAL (complex.contains(array[2]), true)

.CHECK_EQUAL (complex.size(), 3)
.CHECK_OK    (complex.insert(array[3]))
.CHECK_EQUAL (complex.contains(array[3]), true)



 .CHECK_EQUAL (complex.contains(array[0]), true)


 .CHECK_EQUAL (complex.size(), 1)
 .CHECK_OK    (complex.insert(array[1]))
 .CHECK_EQUAL (complex.contains(array[1]), true)


 .CHECK_EQUAL (complex.size(), 2)
 .CHECK_OK    (complex.insert(array[2]))
 .CHECK_EQUAL (complex.contains(array[2]), true)

 .CHECK_EQUAL (complex.size(), 3)
 .CHECK_OK    (complex.insert(array[3]))
 .CHECK_EQUAL (complex.contains(array[3]), true)

 .CHECK_EQUAL (complex.size(), 4)
 .CHECK_OK    (complex.insert(array[4]))
 .CHECK_EQUAL (complex.contains(array[4]), true)

 .CHECK_EQUAL (complex.size(), 5)
 .CHECK_OK    (complex.insert(array[5]))
 .CHECK_EQUAL (complex.contains(array[5]), true)

 .CHECK_EQUAL (complex.size(), 6)
 .CHECK_OK    (complex.insert(array[6]))
 .CHECK_EQUAL (complex.contains(array[6]), true)

 .CHECK_EQUAL (complex.size(), 7)
 .CHECK_OK    (complex.insert(array[7]))
 .CHECK_EQUAL (complex.contains(array[7]), true)

 .CHECK_EQUAL (complex.size(), 8)
 .CHECK_OK    (complex.insert(array[8]))
 .CHECK_EQUAL (complex.contains(array[8]), true)

 .CHECK_EQUAL (complex.size(), 9)
 .CHECK_OK    (complex.insert(array[9]))
 .CHECK_EQUAL (complex.contains(array[9]), true)




 .CHECK_EQUAL (complex.parent(30), 21)
 .CHECK_EQUAL (complex.parent(5), 21)
 .CHECK_EQUAL (complex.parent(4), 5)
 .CHECK_EQUAL (complex.parent(7), 5)
 .CHECK_EQUAL (complex.parent(14), 7)
 .CHECK_EQUAL (complex.parent(13), 14)
 .CHECK_EQUAL (complex.parent(10), 13)
.CHECK_EQUAL (complex.parent(26), 25)
 .CHECK_EQUAL (complex.parent(25), 30)

 .CHECK_EQUAL (complex.right(21), 30)
 .CHECK_EQUAL (complex.right(5), 7)
 .CHECK_EQUAL (complex.right(7), 14)
 .CHECK_EQUAL (complex.right(25), 26)
 
 .CHECK_EQUAL (complex.left(21), 5)
 .CHECK_EQUAL (complex.left(5), 4)
 .CHECK_EQUAL (complex.left(30), 25)
 .CHECK_EQUAL (complex.left(14), 13)
 .CHECK_EQUAL (complex.left(13), 10)
 



.CHECK_EQUAL (complex.size(), 10)
.CHECK_EQUAL (complex.root(), 21)
.CHECK_OK    (complex.remove(21))
.CHECK_EQUAL (complex.root(), 14)
.CHECK_EQUAL (complex.size(), 9)
.CHECK_EQUAL (complex.left(14), 5)
.CHECK_EQUAL (complex.right(14), 30)
.CHECK_EQUAL (complex.contains(21), false)

.CHECK_OK    (complex.remove(14))
.CHECK_EQUAL (complex.contains(14), false)
.CHECK_EQUAL (complex.root(), 13)
.CHECK_EQUAL (complex.size(), 8)
.CHECK_EQUAL (complex.left(13), 5)
.CHECK_EQUAL (complex.right(13), 30)

.CHECK_OK    (complex.remove(13))
.CHECK_EQUAL (complex.contains(13), false)
.CHECK_EQUAL (complex.root(), 10)
.CHECK_EQUAL (complex.size(), 7)
.CHECK_EQUAL (complex.left(10), 5)
.CHECK_EQUAL (complex.right(10), 30)

.CHECK_OK    (complex.remove(5))
.CHECK_EQUAL (complex.contains(5), false)
.CHECK_EQUAL (complex.root(), 10)
.CHECK_EQUAL (complex.size(), 6)
.CHECK_EQUAL (complex.left(10), 4)
.CHECK_EQUAL (complex.right(4), 7)

.CHECK_OK    (complex.remove(10))
.CHECK_EQUAL (complex.contains(10), false)
.CHECK_EQUAL (complex.root(), 7)
.CHECK_EQUAL (complex.size(), 5)
.CHECK_EQUAL (complex.left(7), 4)
.CHECK_EQUAL (complex.right(7), 30)

.CHECK_OK    (complex.remove(7))
.CHECK_EQUAL (complex.contains(7), false)
.CHECK_EQUAL (complex.root(), 4)
.CHECK_EQUAL (complex.size(), 4)
.CHECK_EQUAL (complex.right(4), 30)

.CHECK_OK    (complex.remove(26))
.CHECK_EQUAL (complex.contains(26), false)
.CHECK_EQUAL (complex.root(), 4)
.CHECK_EQUAL (complex.size(), 3)
.CHECK_EQUAL (complex.right(4), 30)

.CHECK_EQUAL (complex.parent(30), 4)

.CHECK_OK    (complex.remove(30))
.CHECK_EQUAL (complex.contains(30), false)
.CHECK_EQUAL (complex.root(), 4)
.CHECK_EQUAL (complex.size(), 2)
.CHECK_EQUAL (complex.right(4), 25)

.CHECK_EQUAL (complex.parent(25), 4)

.CHECK_OK    (complex.remove(4))
.CHECK_EQUAL (complex.contains(4), false)
.CHECK_EQUAL (complex.root(), 25)
.CHECK_EQUAL (complex.size(), 1)

.CHECK_OK    (complex.remove(25))
.CHECK_EQUAL (complex.contains(25), false)
.CHECK_EQUAL (complex.size(), 0)



.CHECK_EQUAL (complex.size(), 0)
.CHECK_OK    (complex.insert(array[0]))
.CHECK_EQUAL (complex.contains(array[0]), true)


.CHECK_EQUAL (complex.size(), 1)
.CHECK_OK    (complex.insert(array[1]))
.CHECK_EQUAL (complex.contains(array[1]), true)


.CHECK_EQUAL (complex.size(), 2)
.CHECK_OK    (complex.insert(array[2]))
.CHECK_EQUAL (complex.contains(array[2]), true)

.CHECK_EQUAL (complex.size(), 3)
.CHECK_OK    (complex.insert(array[3]))
.CHECK_EQUAL (complex.contains(array[3]), true)

;

  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
