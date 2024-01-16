# TODO
from cs50 import get_int
h = get_int("Height:")
while h <= 0 or h > 8:
    h = get_int("Height:")
for i in range(1, h+1):
    for j in range(h-i):
        print(" ", end = "")
    for p in range(i):
        print("#")
print()
