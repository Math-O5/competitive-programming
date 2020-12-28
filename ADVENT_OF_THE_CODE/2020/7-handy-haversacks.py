########################
## Day 7 - Handy Haversacks
########################

import os
import re

def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-7.txt"
    filepath = os.path.join("inputs", filename)

    with open(filepath) as stream_file:
        content = [line.rstrip(" \n ") for line in stream_file.readlines()]
        
        return content

def make_graph_slave(rules):
    """
        Makes a graph of depency 

        This Bag ->(can contains) Theses Bags
    """
    graph = dict()
    for rule in rules:
        rule = re.split("bags.| bags | bag |contain|[ ]", rule)
        rule = [i for i in rule if i != '']
        
        master = rule[0] + ' ' + rule[1]
        graph[master] = []
        for i in range(2, len(rule)):
            try:
                if(int(rule[i])):
                    graph[master].append([int(rule[i]), rule[i + 1] + ' ' + rule[i + 2]])
                i += 2
            except:
                i += 2


    return graph

def make_graph_master(rules):
    """
        Makes a graph of depency 

        This Bag ->(can contains) Theses Bags
    """
    graph = dict()
    for rule in rules:
        rule = re.split("bags.| bags | bag |contain|[ ]", rule)
        rule = [i for i in rule if i != '']
        
        slave = rule[0] + ' ' + rule[1]
        for i in range(2, len(rule)):
            try:
                if(int(rule[i])):
                    i += 1
                    if rule[i] + ' ' + rule[i + 1] in graph:
                        graph[rule[i] + ' ' + rule[i + 1]].append(slave)
                    else:
                        graph[rule[i] + ' ' + rule[i + 1]] = [slave]

                i += 2
            except:
                i += 2


    return graph

def count_master_bags(graph, master):
    """
        Run breadth deep search in the graph of dependency
    """
    count = 0
    vis = dict()
    queue = [master]
    vis[master] = 1
    c = dict()
    while(len(queue)):
        master = queue.pop()
        if master in graph:
            for bag in graph[master]:
                if(bag not in vis):
                    count += 1
                    try:
                        c[bag] += 1
                    except:
                        c[bag] = 1
                    queue.append(bag)
                    vis[bag] = 1

    return count

def count_slave_bags(graph, master):
    """
        Run breadth deep search in the graph of dependency
    """
    if graph[master] == []:
        return 0

    count = 0
    for slave in graph[master]:
        count += slave[0] + (slave[0] * count_slave_bags(graph, slave[1]))
    return count

def count_options_bags(op):
    count_bags = 0
    rules = read_input()
    if(op==1):
        graph = make_graph_master(rules)
        count_bags = count_master_bags(graph, 'shiny gold')
    else:
        graph = make_graph_slave(rules)
        print(graph)
        count_bags = count_slave_bags(graph, 'shiny gold')

    return count_bags

if __name__ == "__main__":
    part = int(input())
    bags= count_options_bags(part)
    print(bags)