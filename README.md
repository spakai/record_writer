## Synopsis
In probability theory, the birthday problem or birthday paradox concerns the probability that, 
in a set of n randomly chosen people, some pair of them will have the same birthday. 
By the pigeonhole principle, the probability reaches 100% when the number of people reaches 367
(since there are 366 possible birthdays, including February 29). However, 99.9% probability is reached with 
just 70 people, and 50% probability with 23 people - Wikipedia

## Motivation
While studying Think Python - an excellent book by Allen B. Downey , I came across this problem in one of the exercises. I thought it will be a good reason to learn up gnuplot and threadpools.

##Code
There are three classes

Singleton
- A template class that contains a static pointer to an abstract type that can be any class. 
- Passing the type of a class into a template from which the class derives is known as the curiously
recursive template pattern. The code is from the book C++ Recipes by Bruce Sutherland.

Semaphore 
- I've used The Little Book of Semaphores by Allen Downey as reference .
- There are 3 rules 
A semaphore is like an integer, with three differences:
1. When you create the semaphore, you can initialize its value to any integer,
but after that the only operations you are allowed to perform are increment
(increase by one) and decrement (decrease by one). You cannot read the
current value of the semaphore.
2. When a thread decrements the semaphore, if the result is negative, the
thread blocks itself and cannot continue until another thread increments
the semaphore.
3. When a thread increments the semaphore, if there are other threads waiting,
one of the waiting threads gets unblocked.

Record writer
- A class where multiple clients can push records and those records are later written into a file . Supports multiple writers with one reader with writer priority. 

##Tests
Tests were done with Google test.

To run
```bash
mkdir build
cd build
cmake ..
make clean && make
./test
```
