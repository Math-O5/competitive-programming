########################
## Day 12: Rain Risk
########################

import os
import re
import math 

def read_input():
    """
        This function parse the input from file to varibles content
        -----------------------------------------------------------
        Return Array
    """
    filename = "day-12.txt"
    filepath = os.path.join("inputs", filename)

    with open(filepath) as stream_file:
        content = [line.rstrip(" \n ") for line in stream_file.readlines()]
        return content

def coord_navigation():
    insts = read_input()
    coor_vert = 0
    coor_hori = 0
    ang = 0 # 90 north, 270, south
    radians = 0

    for inst in insts:
        print(inst)
        if inst[0] == 'F': 
            coor_vert += round(math.sin(radians) * int(inst[1:]))
            coor_hori += round(math.cos(radians) * int(inst[1:]))

        elif inst[0] == 'L':
            ang = ( ang + int(inst[1:]) ) % 360
            radians = math.radians(ang)

        elif inst[0] == 'R':
            ang = ( ang - int(inst[1:]) ) % 360
            radians = math.radians(ang)

        elif inst[0] == 'N':
            coor_vert += int(inst[1:])

        elif inst[0] == 'S':
            coor_vert -= int(inst[1:])

        elif inst[0] == 'E':
            coor_hori += int(inst[1:])

        elif inst[0] == 'W':
            coor_hori -= int(inst[1:])

        print("%d %d" %(coor_vert, coor_hori))

    return abs(coor_hori) + abs(coor_vert)

def navigation_way_point():
    insts = read_input()
    coor_vert_ship = 0
    coor_hori_ship = 0

    coor_vert_waypoint = 1
    coor_hori_waypoint = 10
    ang = math.degrees(math.atan(coor_vert_waypoint/coor_hori_waypoint)) # 90 north, 270, south

    for inst in insts:
        print(inst)
        if inst[0] == 'F': 
            coor_vert_ship += coor_vert_waypoint *  int(inst[1:])
            coor_hori_ship += coor_hori_waypoint *  int(inst[1:])
  
        elif inst[0] == 'N':
            coor_vert_waypoint += int(inst[1:])

        elif inst[0] == 'S':
            coor_vert_waypoint -= int(inst[1:])

        elif inst[0] == 'E':
            coor_hori_waypoint += int(inst[1:])

        elif inst[0] == 'W':
            coor_hori_waypoint -= int(inst[1:])
        
        else:
            ang = 0
            new_ang = 0
            if coor_hori_waypoint != 0:
                ang = math.degrees(math.atan(coor_vert_waypoint/coor_hori_waypoint))

            ang = int(ang / 90)

            if inst[0] == 'R':
                new_ang = ((ang - (int(inst[1:])/90)) % 4)

            if inst[0] == 'L':
               new_ang = ((ang + (int(inst[1:])/90)) % 4)
            
            if(new_ang == 0 and ang == 1) or (new_ang == 2 and ang == 3):
                coor_vert_waypoint, coor_hori_waypoint = coor_vert_waypoint, -coor_hori_waypoint
            elif(new_ang == 1 and ang == 0) or (new_ang == 3 and ang == 2):
                coor_vert_waypoint, coor_hori_waypoint = coor_vert_waypoint, -coor_hori_waypoint
            elif(new_ang == 1 and ang == 2) or (new_ang == 3 and ang == 0):
                coor_vert_waypoint, coor_hori_waypoint = -coor_vert_waypoint, coor_hori_waypoint
            elif(new_ang == 2 and ang == 1) or (new_ang == 0 and ang == 3):
                coor_vert_waypoint, coor_hori_waypoint = -coor_vert_waypoint, coor_hori_waypoint
            elif(new_ang == 0 and ang == 2) or (new_ang == 1 and ang == 3):
                coor_vert_waypoint, coor_hori_waypoint = -coor_vert_waypoint, -coor_hori_waypoint
            elif(new_ang == 2 and ang == 0) or (new_ang == 3 and ang == 1):
                coor_vert_waypoint, coor_hori_waypoint = -coor_vert_waypoint, -coor_hori_waypoint

    return (abs(coor_hori_ship)) + (abs(coor_vert_ship))

if __name__ == "__main__":
    op = int(input())
    if op == 1:
        manhatttan_dist = coord_navigation()
        print(manhatttan_dist)
    else:
        manhatttan_dist = navigation_way_point()
        print(manhatttan_dist)
        