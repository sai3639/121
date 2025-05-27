# -*- coding: utf-8 -*-
"""
Created on Tue Nov 23 11:15:34 2021

@author: saira

"""

# Date:              29 November 2021

def partb(names, annual_cost, num_products):
    difference =[]
    # num_products - annual_cost =append to difference list
    for i in range(len(annual_cost)):
        diff = num_products[i] - annual_cost[i]
        difference.append(diff)
        
    
    
    # find index # of max difference in difference list
    maxdiff = difference[0]
    count = 0
    for x in difference:
        if x > maxdiff:
            maxdiff = x
            count += 1
        y = difference.index(maxdiff)
        
    #print(x, count)
        
    # compare index # of max difference with index # of names
    maxpro = names[y]
    return maxpro, maxdiff
    #print(maxpro)



#print(list1)
    
    
    
    
    #return
