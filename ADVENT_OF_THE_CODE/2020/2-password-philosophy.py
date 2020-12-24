#############################################
## Day 1: Report Repair               
#############################################
import os

# Part 1
# A password is valid if the frequency of the letter appear in the range [a, b]
#
# The entrie is given: a-b letter: password
#
# Goal: Count the number of valid password

# Part 2
# The password rule was wrong, now the index of a and b must have one and only one ocurrency of the letter
#  

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


def parser(token):
    parts = token.split(' ')
    a, b = parts[0].split('-')
    letter = parts[1][0]
    return a, b, letter, parts[2]

def is_valid(a, b, letter, password):
    freq = {}
    for alpha in password:
        try:
            freq[alpha] += 1
        except:
            freq[alpha] = 1
    try:
        return (freq[letter] >= a and freq[letter] <= b)
    except:
        return False   

def is_valid_two(a, b, letter, password):
    try:
        if(password[a-1] == letter and password[b-1] == letter):
            return False
        elif(password[a-1] == letter or password[b-1] == letter):
            return True
        else:
            return False
    except:
        return False    

def count_valid_passwords():
    """
    """
    passwords = read_input()
    count = 0
    
    for token in passwords:
        a, b, letter, password = parser(token)
        if(is_valid_two(int(a), int(b), letter, password)):
            count += 1
    print(count)

if __name__ == "__main__":
    count_valid_passwords()