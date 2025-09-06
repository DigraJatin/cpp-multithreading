/*
this code is part of a C++ project that demonstrates basic multithreading
using the C++17 standard.

here is a simple example that creates two threads,
each printing a message to the console.

*/
#include <iostream>
#include <thread>

void printHello(int id) {
    std::cout << "Hello from thread " << id << std::endl;
}

int main() {
    std::thread t1(printHello, 1);
    std::thread t2(printHello, 2);
    t1.join();
    t2.join();
    return 0;
}

/* Now, the output of this program when run will not be what you might be expecting.

If you are thinking it will be - 
Hello from thread 1
Hello from thread 2

Then you are wrong. The output can very random because the threads are running concurrently, it can be like -
Hello from thread Hello from thread 21
OR
Hello from thread Hello from thread 2
1
OR something else, we don't know what exactly.

This is because the two threads may interleave their execution in unpredictable ways.
We will learn how to control this behavior in the next examples.
*/
