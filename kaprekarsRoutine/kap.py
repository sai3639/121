# -*- coding: utf-8 -*-
"""
Created on Fri Oct 15 23:13:29 2021

@author: saira

"""

kap(four_digit):
    iterations = 0
    while four_digit != 6174:
        print(four_digit, end = ' > ')
        digit = ''
        digit1 = ''
        for x in range(1):
            four_digit = str(four_digit)
            if len(four_digit) == 4:
                four_digit = four_digit
                #print(type(four_digit))
            elif len(four_digit) == 1:
                four_digit = '0' + '0' + '0' + four_digit
            elif len(four_digit) == 2:
                four_digit = '0' + '0' + four_digit
            elif len(four_digit) == 3:
                four_digit = '0' + four_digit 
            first_integer = four_digit[0]
            seccond_integer = four_digit[1]
            third_integer = four_digit[2]
            fourth_integer = four_digit[3]
            
            max_dig = max(four_digit)
            min_dig = min(four_digit)
            
            min_integer = min(first_integer, second_integer, third_integer, fourth_integer)
            mid_low_integer = min(max(first_integer, second_integer), max(third_integer, fourth_integer))
            mid_high_integer = max(min(first_integer, second_integer), min(third_integer, fourth_integer))
            max_integer = max(first_integer, second_integer, third_integer, fourth_integer)
            
            
            
            
            
            
            
            
            
            
            
            
            
            
#         if int(first_dig) <= int(sec_dig) <= int(third_dig) <= int(fourth_dig):
#             digit = str(first_dig) + str(sec_dig) + str(third_dig) + str(fourth_dig)
#             digit1 = str(fourth_dig) + str(third_dig) + str(sec_dig) + str(first_dig)
#         elif int(first_dig) <= int(third_dig) <= int(sec_dig) <= int(fourth_dig):
#             digit = str(first_dig) + str(third_dig) + str(sec_dig) + str(fourth_dig)
#             digit1 = str(fourth_dig) + str(sec_dig) + str(third_dig) + str(first_dig)
#         elif int(first_dig) <= int(fourth_dig) <= int(third_dig) <= int(sec_dig):
#             digit = str(first_dig) + str(fourth_dig) + str(third_dig) + str(sec_dig)
#             digit1 = str(sec_dig) + str(third_dig) + str(fourth_dig) + str(first_dig)
#         elif int(first_dig) <= int(third_dig) <= int(fourth_dig) <= int(sec_dig):
#             digit = str(first_dig) + str(third_dig) + str(fourth_dig) + str(sec_dig)
#             digit1 = str(sec_dig) + str(fourth_dig) + str(third_dig) + str(first_dig)
#         elif int(first_dig) <= int(fourth_dig) <= int(sec_dig) <= int(third_dig):
#             digit = str(first_dig) + str(fourth_dig) + str(sec_dig) + str(third_dig)
#             digit1 = str(third_dig) + str(sec_dig)+ str(fourth_dig) + str(first_dig)
#         elif int(first_dig) <= int(sec_dig) <= int(fourth_dig) <= int(third_dig):
#             digit = str(first_dig) + str(sec_dig) + str(fourth_dig) + str(third_dig)
#             digit1 = str(third_dig) + str(fourth_dig) + str(sec_dig) + str(first_dig)
#         elif int(sec_dig) <= int(first_dig) <= int(third_dig) <= int(fourth_dig):
#             digit = str(sec_dig) + str(first_dig) + str(third_dig) + str(fourth_dig)
#             digit1 = str(fourth_dig) + str(third_dig) + str(first_dig) + str(sec_dig)
#         elif int(sec_dig) <= int(third_dig) <= int(first_dig) <= int(fourth_dig):
#             digit = str(sec_dig) + str(third_dig) + str(first_dig) + str(fourth_dig)
#             digit1 = str(fourth_dig) + str(first_dig) + str(third_dig) + str(sec_dig)
#         elif int(sec_dig) <= int(fourth_dig) <= int(first_dig) <= int(third_dig):
#             digit = str(sec_dig) + str(fourth_dig) + str(first_dig) + str(third_dig)
#             digit1 = str(third_dig) + str(first_dig) + str(fourth_dig) + str(sec_dig)
#         elif int(sec_dig) <= int(third_dig) <= int(fourth_dig) <= int(first_dig):
#             digit = str(sec_dig) + str(third_dig) + str(fourth_dig) + str(first_dig)
#             digit1 = str(first_dig) + str(fourth_dig) + str(third_dig) + str(sec_dig)
#         elif int(sec_dig) <= int(fourth_dig) <= int(third_dig) <= int(first_dig):
#             digit = str(sec_dig) + str(fourth_dig) + str(third_dig) + str(first_dig)
#             digit1 = str(first_dig) + str(third_dig) + str(fourth_dig) + str(sec_dig)
#         elif int(sec_dig) <= int(first_dig) <= int(fourth_dig) <= int(third_dig):
#             digit = str(sec_dig) + str(first_dig) + str(fourth_dig) + str(third_dig)
#             digit1 = str(third_dig) + str(fourth_dig) + str(first_dig) + str(sec_dig)
#         elif int(third_dig) <= int(sec_dig) <= int(first_dig) <= int(fourth_dig):
#             digit = str(third_dig) + str(sec_dig) + str(first_dig) + str(fourth_dig)
#             digit1 = str(fourth_dig) + str(first_dig) + str(sec_dig) + str(third_dig)
#         elif int(third_dig) <= int(sec_dig) <= int(fourth_dig) <= int(first_dig):
#             digit = str(third_dig) + str(sec_dig) + str(fourth_dig) + str(first_dig)
#             digit1 = str(first_dig) + str(fourth_dig) + str(sec_dig) + str(third_dig)
#         elif int(third_dig) <= int(first_dig) <= int(sec_dig) <= int(fourth_dig):
#             digit = str(third_dig) + str(first_dig) + str(sec_dig) + str(fourth_dig)
#             digit1 = str(fourth_dig) + str(sec_dig) + str(first_dig) + str(third_dig)
#         elif int(third_dig) <= int(first_dig) <= int(fourth_dig) <= int(sec_dig):
#             digit = str(third_dig) + str(first_dig) + str(fourth_dig) + str(sec_dig)
#             digit1 = str(sec_dig) + str(fourth_dig) + str(first_dig) + str(third_dig)
#         elif int(third_dig) <= int(fourth_dig) <= int(first_dig) <= int(sec_dig):
#             digit = str(third_dig) + str(fourth_dig) + str(first_dig) + str(sec_dig)
#             digit1 = str(sec_dig) + str(first_dig) + str(fourth_dig) + str(third_dig)
#         elif int(third_dig) <= int(fourth_dig) <= int(sec_dig) <= int(first_dig):
#             digit = str(third_dig) + str(fourth_dig) + str(sec_dig) + str(first_dig)
#             digit1 = str(first_dig) + str(sec_dig) + str(fourth_dig) + str(third_dig)
#         elif int(fourth_dig) <= int(first_dig) <= int(sec_dig) <= int(third_dig):
#             digit = str(fourth_dig) + str(first_dig) + str(sec_dig) + str(third_dig)
#             digit1 = str(third_dig) + str(sec_dig) + str(first_dig) + str(fourth_dig)
#         elif int(fourth_dig) <= int(first_dig) <= int(third_dig) <= int(sec_dig):
#             digit = str(fourth_dig) + str(first_dig) + str(third_dig) + str(sec_dig)
#             digit1 = str(sec_dig) + str(third_dig) + str(first_dig) + str(fourth_dig)
#         elif int(fourth_dig) <= int(sec_dig) <= int(third_dig) <= int(first_dig):
#             digit = str(fourth_dig) + str(sec_dig) + str(third_dig) + str(first_dig)
#             digit1 = str(first_dig) + str(third_dig) + str(sec_dig) + str(fourth_dig)
#         elif int(fourth_dig) <= int(sec_dig) <= int(first_dig) <= int(third_dig):
#             digit = str(fourth_dig) + str(sec_dig) + str(first_dig) + str(third_dig)
#             digit1 = str(third_dig) + str(first_dig) + str(sec_dig) + str(fourth_dig)
#         elif int(fourth_dig) <= int(third_dig) <= int(sec_dig) <= int(first_dig):
#             digit = str(fourth_dig) + str(third_dig) + str(sec_dig) + str(first_dig)
#             digit1 = str(first_dig) + str(sec_dig) + str(third_dig) + str(fourth_dig)
#         elif int(fourth_dig) <= int(third_dig) <= int(first_dig) <= int(sec_dig):
#             digit = str(fourth_dig) + str(third_dig) + str(first_dig) + str(sec_dig)
#             digit1 = str(sec_dig) + str(first_dig) + str(third_dig) + str(fourth_dig)
#         else: #int(first_dig) == int(sec_dig) == int(third_dig) == int(fourth_dig):
#             digit = str(first_dig) + str(sec_dig) + str(third_dig) + str(fourth_dig)
          
            
#         digit = int(digit)

#         digit1 = int(digit1)
   
         
#         four_digit = ((digit1)) - ((digit))
#         iterations += 1
#     print(four_digit, end='')
#     print("\n"+str(startfour), "reaches 6174 via Kaprekar's routine in", iterations, "iterations")
    
    
            
            
# four_digit = (input("Enter a four-digit integer: "))
# startfour = four_digit
# kap(four_digit)                   
                
        
   
    
   
    
   