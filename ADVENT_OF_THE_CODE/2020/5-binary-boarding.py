########################################
# Binary Boarding
########################################
 
# There is 128 row 0-based
# There is 8 column 0-based

# The string start with 7 charaters with 'F' or 'B' and can locate the rows
# The F in string means that the seat is the the first half of the range: [0,127] -> [0,63]
# The B in string means that the seat is the the second half of the range: [0,127] -> [64,127]

# The string ends with 3 charaters with 'L' or 'R', and can located the cols.

# Part 1 - Find the higest ID seat, iven by ID = row * 8 + col

import os
import re


def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-5.txt"
    filepath = os.path.join("inputs", filename)

    with open(filepath) as stream_file:
        content = [line.rstrip(" \n ") for line in stream_file.readlines()]
        return content


def binary_search(value, low, high):
    i = 0
    while(low < high):

        mid = int((low + high)/2)
        if value[i] in ['F', 'L']:
            high = mid
        else: 
            low = mid + 1
        i += 1
    return low

def decode_id(seat):
    row = binary_search(seat[:7], 0, 127)
    col = binary_search(seat[7:], 0, 7)
    return (8*row) + col

def find_seat_id(op):
    """
    """
    # Entries
    seats = read_input()
    id = -1

    if(op == 1):
        for seat in seats:
            id = max(id, decode_id(seat))
    else:
        taken_seats = []
        for seat in seats:
            id = decode_id(seat)
            taken_seats.append(id)
        
        taken_seats = sorted(taken_seats)
        i = taken_seats[0]
        for seat in taken_seats:
            if(seat == i):
                i += 1
            else:
                id = i
                break
    return id


if __name__ == "__main__":
    part = int(input("Select Part 1 or 2?"))
    print(find_seat_id(part))