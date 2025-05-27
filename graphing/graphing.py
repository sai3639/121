# -*- coding: utf-8 -*-
"""
Created on Tue Nov 16 22:43:52 2021

@author: saira

"""

# Date:         17 November  2021
#plotting - graphs


import numpy as np
import matplotlib.pyplot as plt

# PLOT 1
Plot_one = plt.figure(1)
x = np.linspace(-2.0, 2.0)

f = 2

y1 = (1/(4*f))*x**2

plt.plot(x,y1, color='red', linewidth=2.0, label='f=2')
plt.legend(loc='lower left')

f = 6
y2 = (1/(4*f))*x**2
plt.plot(x,y2, color='blue', linewidth=6.0, label='f=6')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Parabola plots with varying focal length')
plt.legend(loc='lower left')
#plt.axis([-2.0,2.0, 0.0, 0.5])


# PLOT 2
Plot_two = plt.figure(2)
x1 = np.linspace(-4.0, 4.0, 25)

y = 2*x1**3 + 3*x1**2 - 11*x1-6

plt.plot(x1,y, marker=(5, 1), color='yellow')
# plt.axis([-4,4,-50,125])
plt.title("Plot of cubic polynomial")
plt.xlabel('x values')
plt.ylabel('y values')


# PLOT 3
Plot_three = plt.figure(3)

x = np.linspace(-2*np.pi, 2*np.pi)

sin = np.sin(x)
cos = np.cos(x)


plt.subplot(3,1,1)
plt.plot(x,cos, label = 'cos(x)', color = 'maroon')
plt.legend(loc= 'lower right')
plt.ylabel('y=cos(x)')
plt.grid()


plt.title('Plot of cos(x) and sin(x)')




plt.subplot(3,1,2)
plt.plot(x,sin, label = 'sin(x)', color = 'grey')
plt.ylabel('y=sin(x)')
plt.legend(loc = 'upper right')
plt.grid()
plt.subplots_adjust(hspace = .10)

#plt.title('Plot of cos(x) and sin(x)')
plt.xlabel('x')



