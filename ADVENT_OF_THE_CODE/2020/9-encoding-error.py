########################
## Day 9 - Encoding Error
########################

import os
import re

def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-9.txt"
    filepath = os.path.join("inputs", filename)

    with open(filepath) as stream_file:
        content = [line.rstrip(" \n ") for line in stream_file.readlines()]
        content = [int(i) for i in content]
        return content


def pair_k_previous(numbers, target):
    numbers = sorted(numbers)
    start = 0
    end = len(numbers)-1
    while(start < end):
        if numbers[start] + numbers[end] == target:
            return True
        if numbers[start] + numbers[end] > target:
            end -= 1
        if numbers[start] + numbers[end] < target:
            start += 1

    return False

def find_nums(nums, target):
    i = 0
    j = i + 1
    end = len(nums) - 1
    acc = 0
    while(i < end - 1):
        acc = nums[i]
        j = i + 1
        while(j < end and acc < target):
            acc += nums[j]
            j += 1
        if acc == target:
            return nums[i:j]
        i += 1
      
    return [-1]

def decode_xmas(op):
    nums = read_input()
    num = -1
    k_previous = 25
    invalid_nums = []
    if(op == 1):
        for curr, n in enumerate(nums[k_previous:], start=k_previous):
            start = curr - (k_previous)
            if(pair_k_previous(nums[start:curr], n) is False):
                num = n
                break
    else:
        last_idx = -1
        for curr, n in enumerate(nums[k_previous:], start=k_previous):
            start = curr - (k_previous)
            if(pair_k_previous(nums[start:curr], n) is False):
                num = n
                last_idx = curr
                break
        
        invalid_nums = find_nums(nums[:last_idx], num)

        if(len(invalid_nums) >= 2):
            highest = max(invalid_nums)
            lowest = min(invalid_nums) 
            num = highest + lowest
            print(lowest)
            print(highest)
            print(num)

    return num

if __name__ == "__main__":
    part = int(input())
    num = decode_xmas(part)
    print(num)