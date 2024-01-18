class Jar:
    def __init__(self, capacity=12):
        self.capacity  = capacity
        self.cookies = 0
        if self.capacity < 0:
            raise ValueError("Capacity cannot be negative")

    def __str__(self):
        return "🍪" * self.cookies
    def deposit(self, n):
        if self.cookies + n > self.capacity:
            raise ValueError("Exceed capacity")
        else:
            self.cookies += n
            return self.cookies

    def withdraw(self, n):
        if n - self.cookies >= 0:
            self.cookies -= n
        else:
            raise ValueError("Do not have enough cookies")

    @property
    def capacity(self):
        return self.capacity - self.cookies

    @property
    def size(self):
        return self.cookies

def main():
    jar = Jar()
    print(str(jar.capacity))

main()

