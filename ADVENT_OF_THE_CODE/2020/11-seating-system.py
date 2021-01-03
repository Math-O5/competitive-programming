########################
## Day 11: Seating System
########################

import os
import re

def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-11.txt"
    filepath = os.path.join("inputs", filename)

    with open(filepath) as stream_file:
        content = [line.rstrip(" \n ") for line in stream_file.readlines()]
        content = [list(i) for i in content]
        return content


def is_valid(i, j, n, m):
    return (i >= 0 and i < n and j >= 0 and j < m)
    
def fill_seats(seats):
    
    i = 0
    j = 0
    n = len(seats)
    m = len(seats[0])
    tmp_seats = [seat[:] for seat in seats]

    changed = False 
    count_num_seat = 0

    next_pos = [[1, 0], [0, 1], [-1, 0], [0, -1], [1,1], [-1, -1], [-1, 1], [1, -1]]
    
    while i < n:
        j = 0
        while j < m:  
            count_adj_seat = 0
            for position in next_pos:
                a = i + position[0]
                b = j + position[1]
                if is_valid(a, b, n, m):
                    if seats[a][b] == "#":
                        count_adj_seat += 1

            if seats[i][j] == "#" and count_adj_seat >= 4:
                tmp_seats[i][j] = "L"
                changed = True

            if seats[i][j] == "L" and count_adj_seat == 0:
                tmp_seats[i][j] = "#"
                changed = True

            if tmp_seats[i][j] == "#":
                count_num_seat += 1

            j += 1
        i += 1

    return changed, count_num_seat, tmp_seats

def fill_seats_2(seats):
    
    i = 0
    j = 0
    n = len(seats)
    m = len(seats[0])
    tmp_seats = [seat[:] for seat in seats]

    changed = False 
    count_num_seat = 0

    next_pos = [[1, 0], [0, 1], [-1, 0], [0, -1], [1,1], [-1, -1], [-1, 1], [1, -1]]
    
    while i < n:
        j = 0
        while j < m:  
            count_adj_seat = 0
            for position in next_pos:
                a = i + position[0]
                b = j + position[1]
                while is_valid(a, b, n, m):
                    if seats[a][b] == "#":
                        count_adj_seat += 1
                        break
                
                    if seats[a][b] == "L":
                        break

                    a = a + position[0]
                    b = b + position[1]

            if seats[i][j] == "#" and count_adj_seat >= 5:
                tmp_seats[i][j] = "L"
                changed = True

            if seats[i][j] == "L" and count_adj_seat == 0:
                tmp_seats[i][j] = "#"
                changed = True

            if tmp_seats[i][j] == "#":
                count_num_seat += 1

            j += 1
        i += 1

    return changed, count_num_seat, tmp_seats

def challenge_eleven(op):

    num_seat = 0
    seats = read_input()

    print(seats)

    if op == 1:
        changed = True 
        while changed is True:
            changed, num_seat, seats = fill_seats(seats) 
    else:
        changed = True 
        while changed is True:
            changed, num_seat, seats = fill_seats_2(seats) 

    return num_seat

if __name__ == "__main__":
    op = int(input())
    num_seat = challenge_eleven(op)
    print(num_seat)