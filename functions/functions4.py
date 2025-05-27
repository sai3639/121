# -*- coding: utf-8 -*-
"""
Created on Tue Nov 23 11:56:17 2021

@author: saira

"""

# Date:              29 November 2021
#change csv file to tsv file

def partd(filename):
    tsv = []
    # open file 
    with open(filename, 'r') as filecsv:
        #header = filecsv.readline()
        for line in filecsv:
            eachline = line.strip('\n').split(',')
            tsv.append(eachline)
        with open('test.tsv', 'w') as filetsv:
            for line in tsv:
                for word in line:
                    filetsv.write(word + '\t')
    return "Done!"
    
partd('filecsv.txt')        
    # for line in tsv:
    #     for 
    # with open(filename, 'w') as filetsv:
    #     filetsv.write(eachline)
       # tsv.append(eachline)
        # write file
# with open(filename, 'w') as filetsv:
#     for line in tsv:
#         filetsv.write(eachline + '\t')
#     print(filetsv)
    #return filetsv
        
            
