# -*- coding: utf-8 -*-
"""
Created on Thu Nov 18 21:29:35 2021

@author: saira

"""

# Date:         19 November  2021


import numpy as np
import matplotlib.pyplot as  plt

v = np.array([1,
              0])
matrix = np.array([[1.00583, -0.087156], 
                [0.087156, 1.00583]])
#print(np.matmul(v, matrix))

points = []
x = []
y = []
for num in range(250):
    product = np.matmul(matrix,v) # multiply matrix and point together
    v = product
    
    #print(product)
    #points.append(product)
    x.append(product[0])
    y.append(product[1])
    
    plt.plot(x,y)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Spiral')

    
    
#plt.plot(points)


    
