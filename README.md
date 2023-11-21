A vector in programming, often referred to as a dynamic array, is a flexible and resizable container that stores elements in a contiguous memory block. It provides dynamic memory allocation, allowing for efficient insertion, deletion, and access of elements. Vectors are widely used for managing collections of data in various applications, offering a balance between the array's constant-time access and the linked list's dynamic resizing capabilities. They automatically handle memory management and offer functionalities like resizing, appending, and random access, making them a versatile and essential data structure in many programming languages and applications.

Brief descriptions of vector methods are provided below

Size:
Description: Returns the current number of elements in the vector.

Max_size:
Description: Returns the maximum number of elements that the vector can potentially hold.

Resize:
Description: Changes the size of the vector. If the new size is larger, new elements are default-constructed or initialized with a given value. If the new size is smaller, elements are removed.

Capacity:
Description: Returns the current size of the allocated storage capacity for the vector.

Empty:
Description: Tests whether the vector is empty, i.e., whether it contains no elements.

Reserve:
Description: Requests a change in capacity, ensuring that the vector can accommodate a specified number of elements without reallocation.

Shrink_to_fit:
Description: Reduces the vector's capacity to fit its size, freeing up unnecessary memory.

At:
Description: Accesses the element at a specified position in the vector, performing bounds checking to ensure the index is within the valid range.

Front:
Description: Accesses the first element in the vector.

Back:
Description: Accesses the last element in the vector.

Data:
Description: Returns a pointer to the underlying array of elements.

Assign:
Description: Assigns new values to the vector, replacing its current content.

Push_back:
Description: Adds a new element at the end of the vector, increasing its size.

Pop_back:
Description: Removes the last element from the vector, reducing its size.

Insert:
Description: Inserts elements into the vector at a specified position.

Erase:
Description: Removes elements from the vector at a specified position or range.

Swap:
Description: Exchanges the contents of two vectors.

Clear:
Description: Removes all elements from the vector, leaving it with a size of 0.

Emplace:
Description: Constructs and inserts an element at a specified position in the vector.

Emplace_back:
Description: Constructs and inserts an element at the end of the vector.


These methods collectively provide a comprehensive set of functionalities for managing the size, capacity, and content of a C++ vector.

