#include <iostream>

class DynamicArray {
private:
    int *data;
    int capacity;
    int size;

public:
    DynamicArray() : data(nullptr), capacity(0), size(0) {}

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(int value) {
        if (size >= capacity) {
            int new_capacity = (capacity == 0) ? 1 : capacity * 2;
            int *new_data = new int[new_capacity];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        data[size++] = value;
    }

    int at(int index) const {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of range\n";
            exit(1);
        }
        return data[index];
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of range\n";
            exit(1);
        }
        return data[index];
    }

    int get_size() const {
        return size;
    }
};

int main() {
    DynamicArray arr;
    for (int i = 0; i < 10; ++i) {
        arr.push_back(i);
    }
    for (int i = 0; i < arr.get_size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}