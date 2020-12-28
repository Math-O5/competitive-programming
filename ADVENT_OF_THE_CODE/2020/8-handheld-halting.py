########################
## Day 8 - Handheld Halting
########################

import os
import re

def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-8.txt"
    filepath = os.path.join("inputs", filename)

    with open(filepath) as stream_file:
        content = [line.rstrip(" \n ") for line in stream_file.readlines()]
        content = [i.split(' ') for i in content]
        return content

def first_loop(inst):
    acc = 0
    vis = dict()
    
    i = 0
    while(i < len(inst)):
        if i in vis:
            break 
        else:
            vis[i] = 1

        if inst[i][0] == "acc":
            acc += int(inst[i][1])
        elif inst[i][0] == "jmp":
            i += int(inst[i][1])
            continue
        i += 1
        
    return acc

def find_loop(inst):
    acc = 0
    vis = dict()
    
    i = 0
    while(i < len(inst)):
        
        # Found loop
        if i in vis:
            return -1 
        else:
            vis[i] = 1

        if inst[i][0] == "acc":
            acc += int(inst[i][1])
        elif inst[i][0] == "jmp":
            i += int(inst[i][1])
            continue
        i += 1
        
    return acc

def display_acumulator(op):
    acc = 0
    instructions = read_input()
    print(instructions)

    if(op == 1):
        acc = first_loop(instructions)
    else:
        acc = -1
        for i in range(len(instructions)):
            if(instructions[i][0] == "jmp"):
                instructions[i][0] = "nop"
                acc = find_loop(instructions)
                instructions[i][0] = "jmp"
            elif(instructions[i][0] == "nop"):
                instructions[i][0] = "jmp"
                acc = find_loop(instructions)
                instructions[i][0] = "nop"
            
            if(acc != -1):
                break

    return acc

if __name__ == "__main__":
    part = int(input())
    acc = display_acumulator(part)
    print(acc)