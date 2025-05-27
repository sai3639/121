# -*- coding: utf-8 -*-
"""
Created on Sat Nov 20 20:56:45 2021

@author: saira

"""

# Date:         22 November 2021
# #  return
#main()


def readfile(name):
   list_point = []
   with open(name) as badbull:
       badbull.readline()
       line = badbull.readlines()
       for i in line:
           i = i.rstrip('\n').split(',')
           list_point.append([int(i[0]),int(i[1])])
   return list_point

def cross(list1, list2):
    cross_product = (list1[0]*list2[1]) - (list1[1]*(list2[0]))
    return cross_product

def shoelace(list3):
    area = 0
    for i in range(len(list3)):
        if i == len(list3)-1:
            area +=cross(list3[-1],list3[0])
        else:
            area+= cross(list3[i], list3[i+1])
    return area/2

def main():
    name = input("Please enter the filename: ")
    list_point = readfile(name)
    print("The area of the polygon is {}".format(shoelace(list_point)))

if __name__=='__main__':
    main()
