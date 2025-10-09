#ifndef STACKVECTOR_H
#define STACKVECTOR_H

#include <vector>
#include <cstddef>

class StackVector {
private:
    std::vector<int> data;

public:
    void push(int value);
    void pop();
    int& top();
    bool empty() const;
    size_t size() const;
    double average() const;
};

#endif

