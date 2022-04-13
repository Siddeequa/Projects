# -*- coding: utf-8 -*-
"""
Created on Wed Feb 10 21:19:57 2021

@author: Siddeequa
"""

# This program will output the number of vowels in a particular string.

# Example of a string
s = 'azcbobobegghkl'

# Initialise vowels count
vowels = 0

# Loop over string letter by letter
for i in s:
    # If letter is a vowel
    if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == "u":
        # Increment count by 1
        vowels += 1
# Print out number of vowels
print('Number of vowels: ' + str(vowels))
        