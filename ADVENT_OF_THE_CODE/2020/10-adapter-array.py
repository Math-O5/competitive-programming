########################
## Day 10 - Adapter Array
########################

import os
import re

def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-10.txt"
    filepath = os.path.join("inputs", filename)

    with open(filepath) as stream_file:
        content = [line.rstrip(" \n ") for line in stream_file.readlines()]
        content = [int(i) for i in content]
        return content

def mount_chain(charges):
    """
    """
    rate_outlet = 0
    count_diff_one = 0
    count_diff_two = 1

    charges = sorted(charges)

    for charge in charges:
        print(charge)
        if charge-rate_outlet == 1:
            count_diff_one += 1

        elif charge-rate_outlet == 3:
            count_diff_two += 1

        elif charge-rate_outlet != 2:
            return -1, -1

        rate_outlet = charge

    return count_diff_one, count_diff_two


def count_diff_chain(op):
    """
    """
    count_diff_one = 0
    count_diff_two = 0

    charges = read_input()

    if op == 1:
        count_diff_one, count_diff_two = mount_chain(charges)

    else:
        count_diff_one = 0
        count_diff_two = 0

    print(count_diff_one)
    print(count_diff_two)
    return count_diff_one * count_diff_two


if __name__ == "__main__":
    part = int(input())
    print(count_diff_chain(part))