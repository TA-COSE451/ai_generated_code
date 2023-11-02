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
#include <mutex>
#include <condition_variable>
#include <vector>

const int n_threads = 5; // Adjust the number of threads as needed

std::mutex mtx;
std::condition_variable cv;
bool work_done = false;

void myfunc(void* p) {
    while (true) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [] { return work_done; }); // Wait until signaled by main
        }
        
        // Do some work here with the memory area pointed to by 'p'
        
        {
            std::unique_lock<std::mutex> lock(mtx);
            work_done = false;
            cv.notify_one(); // Signal main that work is done
        }
    }
}

int main() {
    void* myp[n_threads] = {nullptr}; // Initialize with your memory locations
    
    std::vector<std::thread> mythread;
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread.emplace_back(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            work_done = true;
            cv.notify_all(); // Signal worker threads to start working
            cv.wait(lock, [] { return !work_done; }); // Wait until all workers finish
        }

        mix_data(myp);

        // You can add any other processing you need to do here
    }

    // Join threads when done
    for (auto& t : mythread) {
        t.join();
    }

    return 0;
}
