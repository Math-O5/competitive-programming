"""
    Daily Byte 1

    “Cat”, return “taC”
    “The Daily Byte”, return "etyB yliaD ehT”
    “civic”, return “civic”

"""
from functools import reduce

# Slicing

my_string = input()
reversed_string = my_string[::-1]
print(reversed_string)


def body_reduce(x, y):
    """
        See inside the reduce!
    """
    print("X and y: ", x, y)
    return y + x

# Reducing
print(reduce(lambda x, y: body_reduce(x, y), my_string))
reversed_string_list = reversed(my_string)
