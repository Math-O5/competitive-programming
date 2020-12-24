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
# if it find no solution, remove the previous choosed number and take the second number and apply the function, until list
# ends of find the numbers.

GOLD_NUMBER = 2020

def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-1.txt"
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


def find_2_num_sum(report, gold_number):
    """
    """
    i = 0
    n = len(report)-1
    while(i < n):
        if(report[i] + report[n] == gold_number):
            return report[i], report[n]
        elif(report[i] + report[n] > gold_number):
            n = n -1
        else:
            i = i + 1
    return -1, -1

def find_3_num_sum(report, gold_number):
    """
    """
    while(len(report) >= 3):
        num_c = report.pop(0)
        num_a, num_b = find_2_num_sum(report, gold_number - num_c)
        if num_a != -1 and num_b != -1:
            return num_a, num_b, num_c

    return -1, -1, -1

def repair_report(options):
    """
    """
    report = sorted(read_input());
    num_a = 0
    num_b = 0
    num_c = 1
    if(options == 2):
        num_a, num_b = find_2_num_sum(report, GOLD_NUMBER)
    else:
        num_a, num_b, num_c = find_3_num_sum(report, GOLD_NUMBER)
    
    if(num_a == -1 or num_b == -1):
        print("No such numbers")
    else:
        print(num_a * num_b * num_c)

if __name__ == "__main__":
    options = int(input("Find 2 or 3 numbers?"))
    repair_report(options)    