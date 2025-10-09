#include "StackVector.h"
#include <numeric>
#include <stdexcept>

void StackVector::push(int value) {
    data.push_back(value);
}

void StackVector::pop() {
    if (!data.empty()) data.pop_back();
}

int& StackVector::top() {
    if (data.empty()) throw std::runtime_error("Stack is empty");
    return data.back();
}

bool StackVector::empty() const {
    return data.empty();
}

size_t StackVector::size() const {
    return data.size();
}

double StackVector::average() const {
    if (data.empty()) return 0.0;
    long long sum = std::accumulate(data.begin(), data.end(), 0LL);
    return static_cast<double>(sum) / data.size();
}
