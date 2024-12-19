
#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

// NOTE: You may not include any other libraries!
#include <unordered_map>
#include <vector>
#include <utility> // Has pair and swap

using namespace std;

template <typename T>
class MinPriorityQueue
{
    // For the mandatory running times below:
    //
    // n is the number of strings in the MinPriorityQueue.
    //
    // Assume the operations of map are O(1) time
    // (they are average case, but not worst-case).

public:
    // Creates an empty MinPriorityQueue
    MinPriorityQueue()
    {
        // TODO
    }

    // Returns the number of elements in the MinPriorityQueue.
    //
    // Must run in O(1) time.
    int size()
    {
        return H.size();
    }

    // Pushes a new element x with priority p
    // into the MinPriorityQueue.
    //
    // Must run in O(log(n)) time.
    void push(T x, int p)
    {
        H.push_back({x, p});
        I[x] = H.size() - 1;
        heapify_up(H.size() - 1);
    }

    // Returns the string at the front of the MinPriorityQueue.
    // Undefined behavior if the MinPriorityQueue is empty.
    //
    // Must run in O(1) time.
    T front()
    {
        return H.front().first;
    }

    // Removes the string at the front of the MinPriorityQueue.
    // Undefined behavior if the MinPriorityQueue is empty.
    //
    // Must run in O(log(n)) time.
    void pop()
    {
        if (size() > 1) {
            I[H.front().first] = -1;  // Mark as removed
            H.front() = H.back();
            I[H.front().first] = 0;
            H.pop_back();
            heapify_down(0);
        } else if (size() == 1) {
            I[H.front().first] = -1;  // Mark as removed
            H.pop_back();
        }
    }

    // If s is in the MinPriorityQueue
    // with current priority at least new_p,
    // then changes the priority of x to new_p.
    // Undefined behavior otherwise.
    //
    // Must run in O(log(n)) time.
    void decrease_key(T x, int new_p)
    {
        int index = I[x];
        if (new_p < H[index].second) {
            H[index].second = new_p;
            heapify_up(index);
        }
    }

private:
    // You don't need any other instance variables,
    // but you can add some if you want to.
    unordered_map<T, int> I; // Maps elements to indices in H.
    vector< pair<T, int> > H;     // The array containing the heap.

    void heapify_up(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (H[i].second < H[parent].second) {
                std::swap(H[i], H[parent]);
                I[H[i].first] = i;
                I[H[parent].first] = parent;
                i = parent;
            } else {
                break;
            }
        }
    }

    void heapify_down(int i) {
        while (2 * i + 1 < size()) {
            int left_child = 2 * i + 1;
            int right_child = 2 * i + 2;
            int smallest_child = left_child;

            if (right_child < size() && H[right_child].second < H[left_child].second) {
                smallest_child = right_child;
            }

            if (H[i].second > H[smallest_child].second) {
                std::swap(H[i], H[smallest_child]);
                I[H[i].first] = i;
                I[H[smallest_child].first] = smallest_child;
                i = smallest_child;
            } else {
                break;
            }
        }
    }
};

#endif
