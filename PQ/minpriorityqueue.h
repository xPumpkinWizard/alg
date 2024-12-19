
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
    // n is the number of elements in the MinPriorityQueue.
    //
    // Assume that the operations of unordered_map are O(1) time
    // (they are average case, but not worst-case).

public:
    // Creates an empty MinPriorityQueue
    MinPriorityQueue()
    {
        H.clear();
        I.clear();
    }

    // Returns the number of elements in the MinPriorityQueue.
    //
    // Must run in O(1) time.
    int size()
    {
        return H.size();
    }

    // Pushes a new value x with priority p
    // into the MinPriorityQueue.
    //
    // Must run in O(log(n)) time.
    void push(T x, int p)
    {
        H.push_back(make_pair(x, p));
        int index = H.size() - 1;

        I[x] = index;
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (H[index].second < H[parentIndex].second) {
                swap(H[index], H[parentIndex]);
                I[H[index].first] = index;
                I[H[parentIndex].first] = parentIndex;
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // Returns the value at the front of the MinPriorityQueue.
    // Undefined behavior if the MinPriorityQueue is empty.
    //
    // Must run in O(1) time.
    T front()
    {
        return H[0].first;
    }

    // Removes the value at the front of the MinPriorityQueue.
    // Undefined behavior if the MinPriorityQueue is empty.
    //
    // Must run in O(log(n)) time.
    void pop()
    {
        if (H.empty()) {
            return;
        }

        I.erase(H[0].first);
        int lastIndex = H.size() - 1;
        swap(H[0], H[lastIndex]);
        H.pop_back();

        int index = 0;
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int minIndex = index;
            if (leftChild < H.size() && H[leftChild].second < H[minIndex].second) {
                minIndex = leftChild;
            }
            if (rightChild < H.size() && H[rightChild].second < H[minIndex].second) {
                minIndex = rightChild;
            }
            if (minIndex != index) {
                swap(H[index], H[minIndex]);
                I[H[index].first] = index;
                I[H[minIndex].first] = minIndex;
                index = minIndex;
            } else {
                break;
            }
        }
    }

    // If x is in the MinPriorityQueue
    // with current priority at least new_p,
    // then changes the priority of x to new_p.
    // Undefined behavior otherwise.
    //
    // Must run in O(log(n)) time.
    void decrease_key(T x, int new_p)
    {
        if (I.find(x) != I.end()) {
            int index = I[x];
            if (new_p < H[index].second) {
                H[index].second = new_p;

                while (index > 0) {
                    int parentIndex = (index - 1) / 2;
                    if (H[index].second < H[parentIndex].second) {
                        swap(H[index], H[parentIndex]);
                        I[H[index].first] = index;
                        I[H[parentIndex].first] = parentIndex;
                        index = parentIndex;
                    } else {
                        break;
                    }
                }
            }
        }
    }

private:
    // You don't need any other instance variables,
    // but you can add some if you want to.
    vector< pair<T, int> > H; // The heap.
    unordered_map<T, int> I;  // Maps values to their indices in H.
};

#endif
