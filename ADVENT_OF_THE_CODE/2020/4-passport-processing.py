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

# Part 2
# Validate the required fields

import os
import re


def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-4.txt"
    filepath = os.path.join("inputs", filename)

    with open(filepath) as stream_file:
        content = [line.rstrip(" \n ") for line in stream_file.readlines()]

        for i in range(len(content)):
            if content[i] == '': 
                content[i] = '\n'
        content = " ".join(content).split(" \n ")

        return content


def extract_fields(passport):
    """
    """
    passport = passport.split(' ')
    fields = {}
    for field in passport:
        key, value = field.split(':')
        fields[key] = value 
    return fields


def system_temp_check(passport):
    """
    """
    valid_fields = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"]
    fields = extract_fields(passport)
    
    count = 0
    for key in fields.keys():
        if(key in valid_fields):
            count += 1 

    return (count == len(valid_fields))

def is_valid_byr(value):
    """
    """
    try:
        if len(value) == 4 and int(value) >= 1920 and int(value) <= 2002:
            return True
        else:
            return False
    except:
        return False


def is_valid_iyr(value):
    """
    """
    if len(value) == 4 and int(value) >= 2010 and int(value) <= 2020:
        return True
    return False


def is_valid_eyr(value):
    """
    """
    if len(value) == 4 and int(value) >= 2020 and int(value) <= 2030:
        return True
    return False


def is_valid_hgt(value):
    """
    """
    try:
        if value.endswith('cm') and \
            150 <= int(value[:-2]) <= 193:          
            return True
        elif value.endswith('in') and \
            59 <= int(value[:-2]) <= 76:       
            return True
        else:
            return False
    except:
        return False

def is_valid_hcl(value):
    """
    """
    match = re.search(r'^#(?:[0-9a-f]{3}){1,2}$', value[1:])
    return (len(value)==7 and value[0] == '#' and match)

def is_valid_ecl(value):
    """
    """
    options = ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"]
    if (value in options):
        return True
    else:
        return False

def is_valid_pid(value):
    """
    """
    if len(value) == 9 and value.isdecimal():
        return True
    else:
        return False

def system_temp_check_2(passport):
    valid_fields = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"]
    fields = extract_fields(passport)
    count = 0
    print("0000000000000000000000000000000")
    for key in fields.keys():
        print(key)
        if(key in valid_fields):
            count += 1
            if key == "byr":
                if(is_valid_byr(fields[key]) is False):
                    return False 
            elif key == "iyr":
                if(is_valid_iyr(fields[key]) is False):
                    return False 
            elif key == "eyr":
                if(is_valid_eyr(fields[key]) is False):
                    return False 
            elif key == "hgt":
                if(is_valid_hgt(fields[key]) is False):
                    return False 
            elif key == "hcl":
                if(is_valid_hcl(fields[key]) is False):
                    return False 
            elif key == "ecl":
                if(is_valid_ecl(fields[key]) is False):
                    return False 
            elif key == "pid":
                if(is_valid_pid(fields[key]) is False):
                    return False 

    return (count == len(valid_fields))


def count_valid_passport(op):
    """
    """
    # Entries
    passports = read_input()    
    
    # Counter of trees
    counter_passport = 0
    for passport in passports:
        if op == 1:
            counter_passport += (system_temp_check(passport) == True)
        else:
            counter_passport += (system_temp_check_2(passport) == True)
        
    return counter_passport


if __name__ == "__main__":
    part = int(input("Select Part 1 or 2?"))

    counter_passport = 0

    if(part == 1):
        counter_passport = count_valid_passport(1)
    else:
        counter_passport = count_valid_passport(2)

    print("The number of valid passport is %d" %(counter_passport))
