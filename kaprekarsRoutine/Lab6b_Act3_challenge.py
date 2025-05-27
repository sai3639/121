# -*- coding: utf-8 -*-
"""
Created on Sat Oct 16 00:49:39 2021

@author: saira

"""

# Date:             13 October2021
#

# fix this thng
# inputs


def kap(four_digit, first_dig, sec_dig, third_dig, fourth_dig):
    iterations = 0
    while four_digit != 6174:
        if int(first_dig) == int(sec_dig) == int(third_dig) ==int(fourth_dig):
            print(four_digit, end=' > ')
            four_digit = int(first_dig) - int(sec_dig)
            break
        print(int(four_digit), end = ' > ')
        digit = ''
        digit1 = digit[::-1]
        for x in range(1):
            four_digit = str(four_digit)
            if len(four_digit) == 4:
                four_digit = four_digit
            elif len(four_digit) == 1:
                four_digit = '0' + '0' + '0' + four_digit
            elif len(four_digit) == 2:
                four_digit = '0' + '0' + four_digit
            elif len(four_digit) == 3:
                four_digit = '0' + four_digit 
            four_digit = str(four_digit)
            first_dig = four_digit[0]
            sec_dig = four_digit[1]
            third_dig = four_digit[2]
            fourth_dig = four_digit[3]
            max_dig = max(four_digit)
            min_dig = min(four_digit)
            
            
            if max_dig == first_dig:
                
                if min_dig == fourth_dig:
                    digit = str(fourth_dig)
                    if int(sec_dig) <= int(third_dig):
                        digit += str(sec_dig) + str(third_dig)
                    elif int(sec_dig) >= int(third_dig):
                        digit += str(third_dig) + str(sec_dig)
                elif min_dig == third_dig:
                    digit = str(third_dig)
                    if int(sec_dig) <= int(fourth_dig):
                        digit += str(sec_dig) + str(fourth_dig)
                    elif int(fourth_dig) <= int(sec_dig):
                        digit += str(fourth_dig) + str(sec_dig)
                elif min_dig == sec_dig:
                    digit = str(sec_dig)
                    if int(third_dig) <= int(fourth_dig):
                        digit +=str(third_dig) + str(fourth_dig)
                    elif int(third_dig) >= int(fourth_dig):
                        digit += str(fourth_dig) + str(third_dig)
              
      
            elif max_dig == sec_dig:
            
                if min_dig == first_dig:
                    digit = str(first_dig)
                    if int(third_dig) <= int(fourth_dig):
                        digit += str(third_dig) + str(fourth_dig)
                    elif int(fourth_dig) <= int(third_dig):
                        digit += str(fourth_dig) + str(third_dig)
                elif min_dig == third_dig:
                    digit = str(third_dig)
                    if int(first_dig) <= int(fourth_dig):
                        digit += str(first_dig) + str(fourth_dig)
                    elif int(fourth_dig) <= int(first_dig):
                        digit += str(fourth_dig) + str(first_dig)
                elif min_dig == fourth_dig:
                    digit = str(fourth_dig)
                    if int(first_dig) <= int(third_dig):
                        digit += str(first_dig) + str(third_dig)
                    elif int(third_dig) <= int(first_dig):
                        digit += str(third_dig) + str(first_dig)
                
                        
                    
            elif max_dig == third_dig: 
               
                if min_dig == first_dig:
                    digit = str(first_dig)
                    if int(sec_dig) <= int(fourth_dig):
                        digit += str(sec_dig) + str(fourth_dig) 
                    elif int(fourth_dig) <= int(sec_dig):
                        digit += str(fourth_dig) + str(sec_dig)
                elif min_dig == sec_dig:
                    digit = str(sec_dig)
                    if int(first_dig) <= int(fourth_dig):
                        digit += str(first_dig) + str(fourth_dig) 
                    elif int(fourth_dig) <= int(first_dig):
                        digit += str(fourth_dig) + str(first_dig) 
                elif min_dig == fourth_dig:
                    digit = str(fourth_dig)
                    if int(sec_dig) <= int(first_dig):
                        digit += str(sec_dig) + str(first_dig)
                    elif int(first_dig) <= int(sec_dig):
                        digit += str(first_dig) + str(sec_dig) 
                    
                        
            elif max_dig ==  fourth_dig: 
                    
                    if min_dig == first_dig:
                        digit = str(first_dig)
                        if int(third_dig) <= int(sec_dig):
                            digit += str(third_dig) + str(sec_dig)
                        elif int(sec_dig) <= int(third_dig):
                            digit += str(sec_dig) + str(third_dig) 
                    elif min_dig == sec_dig:
                        digit = str(sec_dig)
                        if int(third_dig) <= int(first_dig):
                            digit += str(third_dig) + str(first_dig) 
                        elif int(first_dig) <= int(third_dig):
                            digit += str(first_dig) + str(third_dig) 
                    elif min_dig == third_dig:
                        digit = str(third_dig)
                        if int(sec_dig) <= int(first_dig):
                            digit += str(sec_dig) + str(first_dig) 
                        elif int(first_dig) <= int(sec_dig):
                            digit += str(first_dig) + str(sec_dig) 
                
                    
            
                
                
                    
                    
        digit += max_dig             
        digit1 = digit[::-1] 
            
        digit = int(digit)

        digit1 = int(digit1)
   
         
        four_digit = ((digit1)) - ((digit))
        iterations += 1
    print(four_digit, end='')
    if int(four_digit) == 6174: 
        print("\n"+str(startfour), "reaches 6174 via Kaprekar's routine in", iterations, "iterations")
    else:
        print("\n"+str(startfour), "reaches 0 via Kaprekar's routine in 1 iterations")
    

    
        
            
            
four_digit = (input("Enter a four-digit integer: "))
four_digit = str(four_digit)
if len(four_digit) == 4:
    four_digit = four_digit
elif len(four_digit) == 1:
    four_digit = '0' + '0' + '0' + four_digit
elif len(four_digit) == 2:
    four_digit = '0' + '0' + four_digit
elif len(four_digit) == 3:
    four_digit = '0' + four_digit 
first_dig = four_digit[0]
sec_dig = four_digit[1]
third_dig = four_digit[2]
fourth_dig = four_digit[3]
startfour = int(four_digit)
kap(four_digit, first_dig, sec_dig, third_dig, fourth_dig)                   




    
   
    
        
