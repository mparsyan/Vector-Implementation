#include "vector.hpp"

// Default constructor
template <typename T>
Vector<T>::Vector() 
{
    m_ptr = nullptr;
    m_size = 0;
    m_capacity = 0;
}

// Parameterized constructor
template <typename T>
Vector<T>::Vector(size_t size, size_t capacity)
    : m_size(size)
    , m_capacity(capacity)
    {
        m_ptr = new T[m_capacity];
    }

// Initializer list constructor
template <typename T>
Vector<T>::Vector(std::initializer_list<T> list)
    : m_size(list.size())
    , m_capacity(m_size)
    {
        m_ptr = new T[m_capacity];

        // Copy elements from the initializer list to the vector
        if (m_size > 0)
        {
            auto it = list.begin();
            for (size_t i = 0; i < m_size; ++i, ++it)
            {
                m_ptr[i] = *it;
            }
        }
    }

// Copy constructor
template <typename T>
Vector<T>::Vector(const Vector& other)
    : m_size(other.m_size)
    , m_capacity(other.m_capacity)
    {
        m_ptr = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i)
        {
            m_ptr[i] = other.m_ptr[i];
        }
    }

// Move constructor
template <typename T>
Vector<T>::Vector(Vector&& other)
    : m_ptr(other.m_ptr)
    , m_size(other.m_size)
    , m_capacity(other.m_capacity)
    {
        other.m_ptr = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }

// Destructor
template <typename T>
Vector<T>::~Vector() 
{
    if (m_ptr)
    {
        delete[] m_ptr;
    }
}

// Copy assignment operator
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)    
{
    if (this != &other)
    {
        delete[] m_ptr;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_ptr = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i)
        {
            m_ptr[i] = other.m_ptr[i];
        }
    }
    return *this;
}

// Move assignment operator
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other)     
{
    if (this != &other) 
    {
        delete[] m_ptr;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_ptr = other.m_ptr;
        other.m_capacity = 0;
        other.m_size = 0;
        other.m_ptr = nullptr;
    }
    return *this;
}

// Subscript operator
template <typename T>
T& Vector<T>::operator[](int index) const
{
    if (index < 0 || index >= m_size)
    {
        std::cerr << "Please input a valid index!" << std::endl;
        throw std::out_of_range("Invalid index");
    }
    return m_ptr[index];
}

// Output stream operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& obj) 
{
    for (size_t i = 0; i < obj.size(); ++i)
    {
        os << obj[i];
        if (i < obj.size() - 1)
        {
            os << " ";
        }
    }
    return os;
}

// Function to get the current size of the vector
template <typename T>
size_t Vector<T>::size() const
{
    return m_size;
}

// Function to get the maximum size the vector can reach
template <typename T>
size_t Vector<T>::max_size() const
{
    return 1073741823;
}

// Function to resize the vector
template <typename T>
void Vector<T>::resize(size_t new_size)
{
    // Check for invalid input
    if (new_size < 0)
    {
        std::cerr << "Please input positive number!" << std::endl;
        return;
    }

    // Resize logic
    if (new_size > m_size)
    {
        // Enlarge the vector
        T* tmp = new T[new_size];
        for (size_t i = 0; i < m_size; ++i)
        {
            tmp[i] = m_ptr[i];
        }
        delete[] m_ptr;
        m_ptr = tmp;
        m_size = new_size;
    }
    else if (new_size < m_size)
    {
        // Shrink the vector
        m_size = new_size;
    }
}

// Function to get the current capacity of the vector
template <typename T>
size_t Vector<T>::capacity() const
{
    return m_capacity;
}

// Function to check if the vector is empty
template <typename T>
bool Vector<T>::empty() const
{
    return m_size == 0;
}

// Function to reserve memory for the vector
template <typename T>
void Vector<T>::reserve(size_t new_size)
{
    // Check for invalid input
    if (new_size < 0)
    {
        std::cerr << "Please input positive number!" << std::endl;
        return;
    }

    // Reserve memory logic
    if (new_size > m_capacity)
    {
        T* tmp = new T[new_size];
        for (size_t i = 0; i < m_size; ++i)
        {
            tmp[i] = m_ptr[i];
        }
        delete[] m_ptr;
        m_ptr = tmp;
        m_capacity = new_size;
    }
}

// Function to reduce the vector's capacity to fit its size
template <typename T>
void Vector<T>::shrink_to_fit()
{
    if (m_size < m_capacity)
    {
        // Shrink the vector
        m_capacity = m_size;
        T* tmp = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i)
        {
            tmp[i] = m_ptr[i];
        }
        delete [] m_ptr;
        m_ptr = tmp;
        tmp = nullptr;
    }
}

// Function to access an element at a specific index with bounds checking
template <typename T>
T& Vector<T>::at(size_t index)
{
    if (index >= 0 && index < m_size)
    {
        return m_ptr[index];
    }

    // Invalid index, display error message and return a reference to the first element to avoid undefined behavior
    std::cerr << "Please input a valid index!" << std::endl;
    return m_ptr[0];
}

// Function to access the first element of the vector
template <typename T>
T& Vector<T>::front()
{
    if (m_size > 0)
    {
        return m_ptr[0];
    }

    // Vector is empty, display error message and return a reference to the first element to avoid undefined behavior
    std::cerr << "Vector is empty!" << std::endl;
    return m_ptr[0];        
}

// Function to access the last element of the vector
template <typename T>
T& Vector<T>::back()
{
    if (m_size > 0)
    {
        return m_ptr[m_size - 1];
    }

    // Vector is empty, display error message and return a reference to the first element to avoid undefined behavior
    std::cerr << "Vector is empty!" << std::endl; 
    return m_ptr[0];
}

// Function to get a pointer to the underlying array
template <typename T>
T* Vector<T>::data()
{
    if (m_size == 0)
    {
        return nullptr;
    }
    return m_ptr;
}

// Function to assign a value to all elements in the vector
template <typename T>
void Vector<T>::assign(size_t new_size, const T& val)
{
    if (new_size != m_size)
    {
        // Deallocate existing memory and allocate new memory
        delete [] m_ptr;
        m_ptr = new T[new_size];
        m_size = new_size;
    }
    // Assign the specified value to all elements
    for (size_t i = 0; i < m_size; ++i)
    {
        m_ptr[i] = val;
    }
}

// Function to add an element to the end of the vector
template <typename T>
void Vector<T>::push_back(const T& elem)
{
    if (m_ptr == nullptr || (m_size == m_capacity))
    {
        // If the vector is empty or at capacity, reallocate memory
        m_capacity = (m_capacity == 0) ? 1 : (m_capacity * 2);
        T* tmp = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i)
        {
            tmp[i] = m_ptr[i];
        }
        delete [] m_ptr;
        m_ptr = tmp;
        tmp = nullptr;
    }
    // Add the new element to the end of the vector
    m_ptr[m_size] = elem;
    ++m_size;
}

// Function to remove the last element from the vector
template <typename T>
void Vector<T>::pop_back() 
{
    if (m_size > 0) 
    {
        // If the vector is not empty, decrease the size
        --m_size;
    } 
    else 
    {
        // Vector is empty, display error message
        std::cerr << "Error: Trying to pop back from an empty vector!" << std::endl;
    }
}

// Function to insert an element at a specific index
template <typename T>
void Vector<T>::insert(size_t index, const T& elem)
{
    if (index >= 0 && index <= m_size)
    {
        // Check if reallocation is needed
        if (m_ptr == nullptr || (m_size == m_capacity))
        {
            m_capacity = (m_capacity == 0) ? 1 : (m_capacity * 2);
            T* tmp = new T[m_capacity];
            for (size_t i = 0; i < m_size; ++i)
            {
                tmp[i] = m_ptr[i];
            }
            delete [] m_ptr;
            m_ptr = tmp;
            tmp = nullptr;
        }
        // Shift elements to make room for the new element
        for (size_t i = m_size; i > index; --i) 
        {
            m_ptr[i] = m_ptr[i - 1];
        }
        // Insert the new element at the specified index
        m_ptr[index] = elem;
        ++m_size;
    }
    else
    {
        // Invalid index, display error message
        std::cerr << "Invalid index for insert!" << std::endl;
    }
}

// Function to erase an element at a specific index
template <typename T>
void Vector<T>::erase(size_t index)
{
    if (index >= 0 && index < m_size)
    {
        // Shift elements to remove the element at the specified index
        for (size_t i = index; i < m_size - 1; ++i)
        {
            m_ptr[i] = m_ptr[i + 1];
        }
        // Decrease the size
        --m_size;
    }
    else
    {
        // Invalid index, display error message
        std::cerr << "Invalid index for erase" << std::endl;
    }
}

// Function to swap the contents of two vectors
template <typename T>
void Vector<T>::swap(Vector& vec)
{
    // Swap sizes
    size_t tmp_size = m_size;
    m_size = vec.m_size;
    vec.m_size = tmp_size;

    // Swap capacities
    size_t tmp_capacity = m_capacity;
    m_capacity = vec.m_capacity;
    vec.m_capacity = tmp_capacity;

    // Swap pointers
    T* tmp_ptr = m_ptr;
    m_ptr = vec.m_ptr;
    vec.m_ptr = tmp_ptr;
}

// Function to clear the vector (set size to 0)
template <typename T>
void Vector<T>::clear()
{
    m_size = 0;
}

// Emplaces a new element at the specified position in the vector.
// Shifts existing elements to make room for the new element.
template <typename T>
void Vector<T>::emplace(int pos, T val)
{
    // Check if the position is valid
    if(pos < 0 || pos > m_size)
    {
        std::cerr << "Invalid operation: Given position is not valid for emplacement!" << std::endl; 
        return;
    }

    else
    {
        // Allocate a new array with increased capacity
        T *tmp = new T[++m_capacity];

        // Copy elements before the specified position
        for (size_t i = 0; i < pos; ++i)
        {
            tmp[i] = m_ptr[i];
        }

        // Emplace the new element at the specified position
        tmp[pos] = val;            

        // Copy elements after the specified position
        for (size_t j = pos; j < m_size; ++j) 
        {
            tmp[j + 1] = m_ptr[j];
        }

        // Deallocate the old memory, update the pointer, and increase the size
        delete[] m_ptr;
        m_ptr = tmp;
        tmp = nullptr;
        m_size++;
    }
}

// Emplaces a new element at the end of the vector.
// Doubles the capacity if necessary before insertion.
template <typename T>
void Vector<T>::emplace_back(T val) 
{
    // Check if the vector is empty
    if (m_ptr == nullptr) 
    {
        // If the vector is empty, allocate memory
        m_capacity = 1;
        m_ptr = new T[m_capacity];
    }

    // Check if the capacity is enough, double it if necessary
    if (m_size + 1 >= m_capacity) 
    {
        m_capacity *= 2;
        // Allocate a new array with doubled capacity
        T* tmp = new T[m_capacity];

        // Copy elements from the old array to the new one
        for (size_t i = 0; i < m_size; ++i) 
        {
            tmp[i] = m_ptr[i];
        }

        // Deallocate the old memory and update the pointer
        delete[] m_ptr;
        m_ptr = tmp;
    }

    // Emplace the new element at the end and increase the size
    m_ptr[m_size++] = val;
}