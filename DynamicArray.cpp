#include <iostream>

class ResizableArray {
private:
    int *elements;
    int currentCapacity;
    int currentSize;

public:
    ResizableArray() : elements(nullptr), currentCapacity(0), currentSize(0) {}

    ~ResizableArray() {
        delete[] elements;
    }

    void append(int value) {
        if (currentSize >= currentCapacity) {
            int newCapacity = (currentCapacity == 0) ? 1 : currentCapacity * 2;
            int *newElements = new int[newCapacity];
            for (int i = 0; i < currentSize; ++i) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            currentCapacity = newCapacity;
        }
        elements[currentSize++] = value;
    }

    int getElementAt(int index) const {
        if (index < 0 || index >= currentSize) {
            std::cerr << "Index out of range\n";
            exit(1);
        }
        return elements[index];
    }

    int& operator[](int index) {
        if (index < 0 || index >= currentSize) {
            std::cerr << "Index out of range\n";
            exit(1);
        }
        return elements[index];
    }

    int getCurrentSize() const {
        return currentSize;
    }
};

int main() {
    ResizableArray array;
    for (int i = 0; i < 10; ++i) {
        array.append(i);
    }
    for (int i = 0; i < array.getCurrentSize(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
