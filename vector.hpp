#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector
{
public:
    Vector();
    Vector(size_t size, size_t capacity);
    Vector(std::initializer_list<T> list);
    Vector(const Vector& other);
    Vector(Vector&& other);
    ~Vector();

    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);
    T& operator[](int index) const;

public:
size_t size() const;
size_t max_size() const;
void resize(size_t new_size);
size_t capacity() const;
bool empty() const;
void reserve(size_t new_size);
void shrink_to_fit();
T& at(size_t index);
T& front();
T& back();
T* data();
void assign(size_t size, const T& val);
void push_back(const T& elem);
void pop_back();
void insert(size_t index, const T& elem);
void erase(size_t index);
void swap(Vector& vec);
void clear();
void emplace(int pos, T val);
void emplace_back(T val);

private:
    T* m_ptr;
    size_t m_size;
    size_t m_capacity;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& obj);

#include "vector_impl.hpp"

#endif