# -*- coding: utf-8 -*-
"""
Created on Tue Nov 23 11:33:59 2021

@author: saira

"""

# Date:              29 November 2021
def partc(name, city, state, zip_code, address):
   label = '{:^}'.format(name) + '\n' + '{:^}'.format(address) + '\n'  + '{:^}'.format(city + ', ' + state + ' ' + zip_code) 
#print(label) 
   return label

# label = '{:^20}'.format(name) + '\n' + '{:^20}'.format(address) + '\n'  + '{:^20}'.format(city + ',' + state + ' ' + zip_code) 
# print(label)
