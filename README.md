## Synopsis


## Motivation


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

1.When you create the semaphore, you can initialize its value to any integer,
but after that the only operations you are allowed to perform are increment
(increase by one) and decrement (decrease by one). You cannot read the
current value of the semaphore.

2.When a thread decrements the semaphore, if the result is negative, the
thread blocks itself and cannot continue until another thread increments
the semaphore.

3.When a thread increments the semaphore, if there are other threads waiting,
one of the waiting threads gets unblocked.

Record writer
- A class where multiple clients can push records and those records are later written into a file . Supports multiple writers with one reader(the one that writes to a file)  with writer priority. 

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
