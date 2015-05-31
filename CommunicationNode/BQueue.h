#ifndef SECURECOMM_BQUEUE_H
#define SECURECOMM_BQUEUE_H

#include <mutex>
#include <condition_variable>
#include <deque>

template <typename T>
class BQueue
{
private:
    std::mutex              d_mutex;
    std::condition_variable d_condition;
    std::deque<T>           d_queue;
public:

    /* mutex nie moze byc kopiowany, trzeba nadpisac domyslne konstruktory. */
    BQueue() {}
    BQueue(const BQueue& bQueue) {}

    void push(T const& value)
    {
        {
            std::unique_lock<std::mutex> lock(this->d_mutex);
            d_queue.push_front(value);
        }
        this->d_condition.notify_one();
    }

    T pop()
    {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        this->d_condition.wait(lock, [=]{ return !this->d_queue.empty(); });
        T rc(std::move(this->d_queue.back()));
        this->d_queue.pop_back();
        return rc;
    }
};

#endif //SECURECOMM_BQUEUE_H