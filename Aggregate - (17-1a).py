class ResizableArray:
    def __init__(self):
        self.max_size = 1
        self.data = [None] * self.max_size
        self.size = 0

    def add(self, value):
        if self.size == self.max_size:
            self.expand(self.max_size * 2)
        self.data[self.size] = value
        self.size += 1

    def expand(self, new_size):
        new_data = [None] * new_size
        for i in range(self.size):
            new_data[i] = self.data[i]
        self.data = new_data
        self.max_size = new_size

    def amortized_runtime(self, num_operations):
        total_cost = 0
        for i in range(num_operations):
            if self.size == self.max_size:
                total_cost += self.max_size
                self.expand(self.max_size * 2)
            total_cost += 1
            self.size += 1
        return total_cost / num_operations

# Testing the ResizableArray class
resizable_array = ResizableArray()
num_operations = 100
amortized_time = resizable_array.amortized_runtime(num_operations)

print("Amortized runtime using aggregate method:", amortized_time)
