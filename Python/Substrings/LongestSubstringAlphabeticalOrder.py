# -*- coding: utf-8 -*-
"""
Created on Wed Feb 10 22:41:48 2021

@author: Siddeequa
"""
# This program will display the longest substring that is in alphabetical order in a string.

# String example
s = 'abcbcdzstuvw'

# We can use ASCII to determine which letter comes before another

# Define variables
# We need 2 variables to hold the string we are working with and the longest one
temp = s[0] # Initialise with first letter in string
longest = s[0]

# Iterate over each letter in string
for i in s[1:]:
    if i >= temp[-1]:
        temp = temp + i
        if len(temp) > len(longest):
            longest = temp
    else:
        temp = i

# Print result
print('Longest substring in alphabetical order is: ' + longest)
