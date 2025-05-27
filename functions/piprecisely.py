# -*- coding: utf-8 -*-
"""
Created on Thu Sep 16 11:18:43 2021

@author: saira

"""

def PrintPrecisely(Num2Print, HowPrecise):
    print("Num2Print = {:.{}F}".format(Num2Print, HowPrecise))
    
    
from numpy import pi as Pie
from math import pi

x = pi * Pie
y = pi / 2 
y *= x
z = x ** pi

PrintPrecisely(x, 88)
PrintPrecisely(y, 88)
PrintPrecisely(z, 88)