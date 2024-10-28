#pragma once

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair();
    Pair(const T1& first, const T2& second);
    Pair(const Pair& other);
    Pair& operator=(const Pair& other);
    
    T1 getFirst() const;
    T2 getSecond() const;
    void setFirst(const T1& first);
    void setSecond(const T2& second);
};

template <typename T1, typename T2>
Pair<T1, T2>::Pair() : first(), second() {}

template <typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& first, const T2& second) : first(first), second(second) {}

template <typename T1, typename T2>
Pair<T1, T2>::Pair(const Pair& other) : first(other.first), second(other.second) {}

template <typename T1, typename T2>
Pair<T1, T2>& Pair<T1, T2>::operator=(const Pair& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

template <typename T1, typename T2>
T1 Pair<T1, T2>::getFirst() const {
    return first;
}

template <typename T1, typename T2>
T2 Pair<T1, T2>::getSecond() const {
    return second;
}

template <typename T1, typename T2>
void Pair<T1, T2>::setFirst(const T1& first) {
    this->first = first;
}

template <typename T1, typename T2>
void Pair<T1, T2>::setSecond(const T2& second) {
    this->second = second;
}

