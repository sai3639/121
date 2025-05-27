# -*- coding: utf-8 -*-
"""
Created on Tue Nov 23 11:56:37 2021

@author: saira

"""

# Date:              29 November 2021
# find minimum, maximum, and median given a list of numbers

import numpy as np
def parte(list1):
    # find max
    maximum = max(list1)
    # find min
    minimum = min(list1)
    # find median
    median = np.median(list1)
    return minimum, median, maximum 
