#include "vector.hpp"

int main() 
{
    // Default constructor
    Vector<int> myVector1;

    // Parameterized constructor
    Vector<int> myVector2(5, 10); // Creates a vector with size 5 and capacity 10

    // Initializer list constructor
    Vector<int> myVector3 = {1, 2, 3, 4, 5};

    // Copy constructor
    Vector<int> myVector4 = myVector3;

    // Move constructor
    Vector<int> myVector5 = std::move(myVector4);

    // Output stream operator
    std::cout << "myVector5: " << myVector5 << std::endl;

    // Subscript operator
    int element = myVector5[2];
    std::cout << "Element at index 2: " << element << std::endl;

    // Copy assignment operator
    Vector<int> myVector6;
    myVector6 = myVector5;

    // Move assignment operator
    Vector<int> myVector7;
    myVector7 = std::move(myVector6);

    // Output stream operator
    std::cout << "myVector7: " << myVector7 << std::endl;

    // Example usage of Vector class
    Vector<int> myVector;

    // Pushing elements into the vector
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);

    // Displaying elements in the vector
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < myVector.size(); ++i) 
    {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    // Modifying vector elements
    myVector.at(1) = 42;

    // Displaying modified elements
    std::cout << "Modified vector elements: ";
    for (size_t i = 0; i < myVector.size(); ++i) 
    {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    // Resizing the vector
    myVector.resize(5);

    // Displaying resized vector elements
    std::cout << "Resized vector elements: ";
    for (size_t i = 0; i < myVector.size(); ++i) 
    {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    // Checking capacity
    std::cout << "Vector capacity: " << myVector.capacity() << std::endl;

    // Checking if the vector is empty
    std::cout << "Is the vector empty? " << (myVector.empty() ? "Yes" : "No") << std::endl;

    // Reserving more space
    myVector.reserve(10);

    // Checking capacity after reservation
    std::cout << "Vector capacity after reservation: " << myVector.capacity() << std::endl;

    // Shrinking to fit
    myVector.shrink_to_fit();

    // Checking capacity after shrinking
    std::cout << "Vector capacity after shrinking: " << myVector.capacity() << std::endl;

    // Accessing front and back elements
    std::cout << "Front element: " << myVector.front() << std::endl;
    std::cout << "Back element: " << myVector.back() << std::endl;

    // Assigning values to all elements
    myVector.assign(myVector.size(), 99);

    // Displaying vector after assignment
    std::cout << "Vector elements after assignment: ";
    for (size_t i = 0; i < myVector.size(); ++i) 
    {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    // Popping back element
    myVector.pop_back();

    // Displaying vector after popping back
    std::cout << "Vector elements after popping back: ";
    for (size_t i = 0; i < myVector.size(); ++i) 
    {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    // Inserting an element at index 1
    myVector.insert(1, 55);

    // Displaying vector after insertion
    std::cout << "Vector elements after insertion: ";
    for (size_t i = 0; i < myVector.size(); ++i) 
    {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    // Erasing element at index 2
    myVector.erase(2);

    // Displaying vector after erasing
    std::cout << "Vector elements after erasing: ";
    for (size_t i = 0; i < myVector.size(); ++i) 
    {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    // Swapping vectors
    Vector<int> anotherVector;
    anotherVector.push_back(10);
    anotherVector.push_back(20);

    std::cout << "Vector 1 before swap: ";
    for (size_t i = 0; i < myVector.size(); ++i) 
    {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector 2 before swap: ";
    for (size_t i = 0; i < anotherVector.size(); ++i) 
    {
        std::cout << anotherVector.at(i) << " ";
    }
    std::cout << std::endl;

    myVector.swap(anotherVector);

    std::cout << "Vector 1 after swap: ";
    for (size_t i = 0; i < myVector.size(); ++i) 
    {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector 2 after swap: ";
    for (size_t i = 0; i < anotherVector.size(); ++i) 
    {
        std::cout << anotherVector.at(i) << " ";
    }
    std::cout << std::endl;

    // Emplace an element at position 1
    myVector.emplace(1, 42);

    // Emplace an element at the end
    myVector.emplace_back(99);

    // Display the elements after emplacing
    std::cout << "Vector elements after emplacement: ";
    for (size_t i = 0; i < myVector.size(); ++i)
    {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    // Clearing the vector
    myVector.clear();

    // Displaying vector after clearing
    std::cout << "Vector elements after clearing: ";
    for (size_t i = 0; i < myVector.size(); ++i) 
    {
        std::cout << myVector.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
