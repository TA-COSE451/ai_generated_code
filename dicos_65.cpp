/*
I have a program with a function which takes a pointer as arg, and a main. The main is creating n threads, each of them running the function on different memory areas depending on the passed arg. Threads are then joined, the main performs some data mixing between the area and creates n new threads which do the the same operation as the old ones.

To improve the program I would like to keep the threads alive, removing the long time necessary to create them. Threads should sleep when the main is working and notified when they have to come up again. At the same way the main should wait when threads are working as it did with join.

I cannot end up with a strong implementation of this, always falling in a deadlock.

Simple baseline code, any hints about how to modify this would be much appreciated


#include <thread>
#include <climits>

...

void myfunc(void * p) {
  do_something(p);
}

int main(){
  void * myp[n_threads] {a_location, another_location,...};
  std::thread mythread[n_threads];
  for (unsigned long int j=0; j < ULONG_MAX; j++) {
    for (unsigned int i=0; i < n_threads; i++) {
      mythread[i] = std::thread(myfunc, myp[i]);
    }
    for (unsigned int i=0; i < n_threads; i++) {
      mythread[i].join();
    }
    mix_data(myp); 
  }
  return 0;
}

*/

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

const int n_threads = 4; // Define the number of threads you want to use
std::mutex mtx; // Mutex for thread synchronization
std::condition_variable cv; // Condition variable for thread synchronization
bool threads_ready = false; // Flag to indicate whether threads should run or sleep

void myfunc(void* p) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return threads_ready; }); // Wait until threads are allowed to run
        // Perform work here
        std::cout << "Thread working on " << p << std::endl;
        // Simulate work with sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        lock.unlock();
    }
}

int main() {
    void* myp[n_threads] = { nullptr }; // Define your memory locations here

    std::vector<std::thread> mythread;
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread.push_back(std::thread(myfunc, myp[i]));
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        // Do main thread work here
        std::cout << "Main thread working" << std::endl;
        // Simulate work with sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::unique_lock<std::mutex> lock(mtx);
        threads_ready = true; // Allow threads to run
        lock.unlock();
        cv.notify_all(); // Notify all threads to wake up

        // Main thread waits for threads to finish their work
        for (unsigned int i = 0; i < n_threads; i++) {
            mythread[i].join();
        }

        // Mix data after threads finish their work
        // mix_data(myp);
        std::cout << "Main thread mixing data" << std::endl;
        // Simulate work with sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        lock.lock();
        threads_ready = false; // Prevent threads from running
        lock.unlock();
    }

    // Join the threads
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
