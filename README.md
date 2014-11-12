07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. add is O(log n) and remove would be O(log n) if trickleDown wasworking
2. I don't think that my destructor would allow a memory leak but I'm not sure if I'm not leaking memory elsewhere

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.1)

	add(7)
	7 would be added as the left child of 16. 
	 > 4, 9, 6, 17, 26, 8, 16, 19, 69, 32, 93, 55, 50, 7
	16 and 7 would then swap places.
	 > 4, 9, 6, 17, 26, 8, 7, 19, 69, 32, 93, 55, 50, 16

	add(3)
	3 would be added as the right child of 7.
	 > 4, 9, 6, 17, 26, 8, 7, 19, 69, 32, 93, 55, 50, 16, 3
	7 and 3 would then swap places. 
	 > 4, 9, 6, 17, 26, 8, 3, 19, 69, 32, 93, 55, 50, 16, 7
	6 and 3 would then swap places. 
	 > 4, 9, 3, 17, 26, 8, 6, 19, 69, 32, 93, 55, 50, 16, 7
	4 and 3 would then swap places.
	 > 3, 9, 4, 17, 26, 8, 6, 19, 69, 32, 93, 55, 50, 16, 7

10.2)

	remove(6)
	6 will be removed from the heap.
	 > x, 9, 8, 17, 26, 50, 16, 19, 69, 32, 93, 55
	55 will be placed in 6's spot in the heap
	 > 55, 9, 8, 17, 26, 50, 16, 19, 69, 32, 93
	55 and 8 will then swap places.
	 > 8, 9, 55, 17, 26, 50, 16, 19, 69, 32, 93
	16 and 55 will then swap places.
	 > 8, 9, 16, 17, 26, 50, 55, 19, 69, 32, 93

	remove(8)
	8 will be removed from the heap.
	 > x, 9, 16, 17, 26, 50, 55, 19, 69, 32, 93
	93 will be placed in 8's spot in the heap.
	 > 93, 9, 16, 17, 26, 50, 55, 19, 69, 32
	93 and 16 will swap places.
	 > 16, 9, 93, 17, 26, 50, 55, 19, 69, 32
	93 and 50 will swap places.
	 > 16, 9, 50, 17, 26, 93, 55, 19, 69, 32


#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3
_Discussion_Exercises.html

10.4)
	Index, i
		Parent of i, (i-(d/i))/d	
		Children of d, (2d*i) + d	
//i'm stumped...


#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

One thing I'm wondering is how these pairs are compared in C++. Why don't we ever have to pull the priority numbers to compare them or the T values?