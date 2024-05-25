#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
using namespace std;

int BUFFER_SIZE = 2;  // Size of the buffer
int NUM_ITEMS = 4;   // Number of items to produce/consume

mutex mtx;
condition_variable not_full;
condition_variable not_empty;
queue<int> buffer;

void producer(int id) {
    for (int i = 0; i < NUM_ITEMS; ++i) {
        unique_lock<mutex> lock(mtx);
        not_full.wait(lock, [] { return buffer.size() < BUFFER_SIZE; });

        buffer.push(i);
        cout << "Producer " << id << " produced " << i << std::endl;

        not_empty.notify_all();
    }
}

void consumer(int id) {
    for (int i = 0; i < NUM_ITEMS; ++i) {
        unique_lock<mutex> lock(mtx);
        not_empty.wait(lock, [] { return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();
        cout << "Consumer " << id << " consumed " << item << std::endl;

        not_full.notify_all();
    }
}

int main() {
    int num_producers = 2;
    int num_consumers = 2;

    vector<thread> producers;
    vector<thread> consumers;

    for (int i = 0; i < num_producers; ++i) {
        producers.push_back(thread(producer, i));
    }

    for (int i = 0; i < num_consumers; ++i) {
        consumers.push_back(thread(consumer, i));
    }

    for (auto& p : producers) {
        p.join();
    }

    for (auto& c : consumers) {
        c.join();
    }

    return 0;
}
