# -*- coding: utf-8 -*-
"""
Created on Wed Feb 10 21:37:39 2021

@author: Siddeequa
"""
# This program will output the number of times a particular substring, 
# in this case, 'bob', appears in a string.

# String example
s = 'azcbobobegghaklbobob'

# bob count
total = 0

# Define substring
substring = 'bob'

# Loop over string by index
for i in range(len(s)):
    # View string by length of substring for comparison
    if s[i:(i+len(substring))] == substring:
        total +=1 

# Print result
print('Number of times bob occurs is: ' + str(total))
                    
