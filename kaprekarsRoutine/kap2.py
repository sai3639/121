# -*- coding: utf-8 -*-
"""
Created on Fri Oct 15 23:28:08 2021

@author: saira

"""

def kap(four_digit):
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
            first_dig = four_digit[0]
            sec_dig = four_digit[1]
            third_dig = four_digit[2]
            fourth_dig = four_digit[3]
        if sec_dig >= first_dig and sec_dig >= third_dig and sec_dig >= fourth_dig:
         x = first_dig
         first_dig = sec_dig
         sec_dig = x
    elif third_dig >= first_dig and third_dig >= sec_dig and third_dig >= fourth_dig:
        x = first_dig
        first_dig = third_dig
        third_dig = x
    elif fourth_dig >= first_dig and fourth_dig >= sec_dig and fourth_dig >= third_dig:
        x = first_dig
        first_dig = fourth_dig
        fourth_dig = x
    elif third_dig >= sec_dig and third_dig >= fourth_dig:
        x = sec_dig
        sec_dig = third_dig
        third_dig = x
    elif fourth_dig >= sec_dig and fourth_dig >= third_dig:
        x = fourth_dig
        fourth_dig = sec_dig
        sec_dig = x
    if fourth_dig >= third_dig:
        x = fourth_dig
        fourth_dig = x
    if third_dig >= sec_dig and third_dig >= fourth_dig:
        x = sec_dig
        sec_dig = third_dig
        third_dig = x
    elif fourth_dig >= sec_dig and fourth_dig >= third_dig:
        x = fourth_dig
        fourth_dig = sec_dig
        sec_dig = x
    if fourth_dig >= third_dig:
        x = fourth_dig
        fourth_dig = third_dig
        third_dig = x
    
    higher = first_dig + sec_dig + third_dig + fourth_dig
    lower = fourth_dig + third_dig + sec_dig + first_dig
    four_digit = int(higher) - int(lower)
            
       # digit = int(digit)

        #digit1 = int(digit1)
   
         
        #four_digit = ((digit1)) - ((digit))
        iterations += 1
    print(four_digit, end='')
    print("\n"+str(startfour), "reaches 6174 via Kaprekar's routine in", iterations, "iterations")
    
    
            
            
four_digit = (input("Enter a four-digit integer: "))
startfour = four_digit
kap(four_digit)                   
                
        
   
    
   
    
   
    
   
    
   
    
   
    
   
    
   
    
   
  