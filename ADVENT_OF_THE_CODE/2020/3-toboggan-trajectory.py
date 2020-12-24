########################################
# Toboggan Trajectory
########################################
 
# Given a map if squares of trees(#) and free paths(.), 

# . . # .
# . # . .
# . . . .

# It's know that the pattern repeat in horizontal

# Part 1
# Starting at the top-left corner of your map and following 
# a slope of right 3 and down 1, how many trees would you encounter?

import os


def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-3.txt"
    filepath = os.path.join("inputs", filename)

    with open(filepath) as stream_file:
        content = [line.rstrip("\n") for line in stream_file.readlines()]

    if len(content) == 1:
        try:
            return int(content[0])
        except:
            try:
                return [int(i) for i in content[0].split()]
            except:
                return content[0]
    else:
        try:
            return [int(i) for i in content]
        except:
            return content


def count_trees_in_the_path(slope, down):
    """
        Count the number of trees in the path

        slope(int) : the interval this will walk in to right
        down(int)  : the interval this will walk in to down
    """
    # Entries
    mapping = read_input()    
    
    # Limit of columns
    end_col = len(mapping[0])
    
    # Counter of trees
    counter_trees = 0

    line = 0
    i = 0
    while(line < len(mapping)):
        if mapping[line][i] == '#':
            counter_trees += 1
        i = (i + slope) % end_col
        line += down

    return counter_trees

if __name__ == "__main__":
    part = int(input("Select Part 1 or 2?"))

    cnt_trees = 0

    if(part == 1):
        cnt_trees = count_trees_in_the_path(3, 1)
    else:
        slopes = [1, 3, 5, 7, 1]
        downs = [1, 1, 1, 1, 2]
        cnt_trees = 1
        for i in range(len(slopes)):
            cnt_trees *= count_trees_in_the_path(slopes[i], downs[i])

    print("The number of trees is %d" %(cnt_trees))
