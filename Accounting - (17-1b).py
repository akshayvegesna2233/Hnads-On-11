class ResizingArray:
    def __init__(self):
        self.capacity = 1
        self.items = [None] * self.capacity
        self.count = 0

    def add(self, value):
        if self.count == self.capacity:
            self.expand(self.capacity * 2)

        self.items[self.count] = value
        self.count += 1

    def expand(self, new_capacity):
        new_items = [None] * new_capacity
        for i in range(self.count):
            new_items[i] = self.items[i]
        self.items = new_items
        self.capacity = new_capacity

    def amortized_runtime_accounting(self, num_operations):
        total_cost = 0
        for i in range(num_operations):
            if self.count == self.capacity:
                total_cost += self.capacity
                self.expand(self.capacity * 2)
            total_cost += 2 
            self.count += 1
        return total_cost / num_operations

# Test the ResizingArray class
array = ResizingArray()
operations = 1000
amortized_runtime = array.amortized_runtime_accounting(operations)

print("Amortized runtime using accounting method:", amortized_runtime)
