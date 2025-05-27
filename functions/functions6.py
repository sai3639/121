# -*- coding: utf-8 -*-
"""
Created on Tue Nov 23 11:56:49 2021

@author: saira

"""

# Date:              29 November 2021
# find average velocity given a list of times and distances


#distances = [0, 1, 5]
#times = [2, 3, 5]

def partf(times, distances):
    velocity = []
    for i in range(len(times)-1):
        if i == (len(times)-1):
            vel = distances[i]/(times[-1])
            velocity.append(vel)
        else:
            vel = (distances[i+1]-distances[i])/(times[i+1] - times[i])
            velocity.append(vel)
    return velocity 
