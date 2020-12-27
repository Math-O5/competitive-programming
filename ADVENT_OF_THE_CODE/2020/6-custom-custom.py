#####################################
# Day 6 Custom Customs
#####################################

import os

def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-6.txt"
    filepath = os.path.join("inputs", filename)

    with open(filepath) as stream_file:
        content = [line.rstrip(" \n ") for line in stream_file.readlines()]
        
        return content

def count_questions(op):
    """
        This function count the question answered "yes"

        Method:

        1. Join the question in one line 
    """
    # Entries
    answers = read_input()
    count_questions = 0

    if(op == 1):
        for i in range(len(answers)):
            if answers[i] == '': 
                answers[i] = '\n'
        answers = " ".join(answers).replace(" ", "").split("\n")

        for answer in answers:
            questions = {None}
            for letter in answer:
                questions.add(letter)
            count_questions += len(questions)-1
    else:
        answers = " ".join(answers).replace("  ", "\n").split("\n")

        for answer in answers:
            questions = {}
            count_lines = 1
            for letter in answer:
                if letter == ' ':
                    count_lines += 1
                    continue
                try:
                    questions[letter] += 1
                except:
                    questions[letter] = 1

            for key in questions.keys():
                if questions[key] == count_lines:
                    count_questions += 1

    return count_questions


if __name__ == "__main__":
    part = int(input("Select Part 1 or 2?"))
    print(count_questions(part))