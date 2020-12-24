#############################################
## Day 1: Report Repair               
#############################################
import os

# Part 1
# Goal: Find two entries that sum to 2020 and then multiply those two numbers together.

# Solution:
# Time: O(nlogn + n)
# Method: Sort all entries in nlog(n), sum the last with the first number, it's is more than
# 2020, take out the last number and take the last again, if it's less, take out the first and the new first again.

# Part 2
# Time: O(nlogn + n)
# Find three numbers with same criteria
# Soluiton: Take the first of the list, apply the find two numbers function with the remain list e gold number decrease by the choose number,
# if it find no solution, remove the previous chosen number and take the second number and apply the function, until list
# ends of find the numbers.

GOLD_NUMBER = 2020

def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-2.txt"
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

def count_valid_password():
    passwords = read_input()
    print(passwords)

if __name__ == "__main__":
    count_valid_password()    