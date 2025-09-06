/*

this code demonstrates the difference between `join` and `detach` in C++ threads.
When using `join`, the main thread waits for the background thread to finish.
When using `detach`, the background thread runs independently, and the main thread does not wait for it.
If the main thread exits before the detached thread finishes, the detached thread may be terminated prematurely.

*/
#include <iostream>
#include <thread>

void task() {
    std::cout << "Running task in background \n";
    for(int i = 0; i < 5; ++i) {
        std::cout << "Task running: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    std::thread t(task);
    // t.join(); // Join the thread to wait for it to finish
    
    t.detach(); // Detach the thread to run independently till the main thread exits
    // sleeping for 1 second to allow some output from the detached thread
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Main thread finishing \n";
    return 0;
}

/* 
The output of above program when run - 
1. When line t.join(); is commented out, the main thread finishes without waiting for 
the t thread to finish it's work, we might see output like below or something else depending
on how much work the thread was able to complete before main thread finished.

Running task in background 
Task running: 0
Task running: 1
Main thread finishing 

2. When line t.join(); is uncommented & t.detach(); is commented, the main thread waits for the t thread to finish its work before exiting, we will see complete output from the t thread.
Running task in background we see complete output from the t thread.

Running task in background 
Task running: 0
Task running: 1
Task running: 2
Task running: 3
Task running: 4
Main thread finishing 

This shows the difference between join and detach in C++ threads.
*/
