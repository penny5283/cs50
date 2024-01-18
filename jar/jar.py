class Jar:
    def __init__(self, capacity=12):
        self.capacity  = capacity
        if self.capacity < 0:
            raise ValueError("Capacity cannot be negative")
    def __str__(self):
        ...

    def deposit(self, n):
        ...

    def withdraw(self, n):
        ...

    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...
