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

#include <thread>
#include <climits>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool isReady = false;

void myfunc(void* p) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return isReady; }); // Wait until isReady is true

        do_something(p);

        // Notify the main thread that the task is done
        cv.notify_one();
    }
}

int main() {
    void* myp[n_threads] = {a_location, another_location, ...};
    std::thread mythread[n_threads];

    // Create and start worker threads
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i] = std::thread(myfunc, myp[i]);
    }

    for (unsigned long int j = 0; j < ULONG_MAX; j++) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            isReady = true; // Signal worker threads to start working
        }
        cv.notify_all(); // Notify all worker threads

        // Main thread does its work here
        mix_data(myp);

        {
            std::unique_lock<std::mutex> lock(mtx);
            isReady = false; // Signal worker threads to sleep
        }
        cv.wait(lock, [] { return !isReady; }); // Wait until isReady is false (all workers have completed)
    }

    // Clean up: join all threads
    for (unsigned int i = 0; i < n_threads; i++) {
        mythread[i].join();
    }

    return 0;
}
