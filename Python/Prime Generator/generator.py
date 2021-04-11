# -*- coding: utf-8 -*-
"""
Created on Fri Mar 19 03:02:56 2021

@author: Siddeequa
"""

def genPrimes():
    """ 
    Returns sequence of prime numbers on successive calls to its next() method 
    """
    # Prime numbers can only be divided by 1 and themselves
    
    # We first return 2 since it is the first prime number
    yield 2
    
    # Initialise counter
    i = 3 # Initialise to 3 since 2 is first prime number and has already been returned
    
    while True: # Infinite loop
        for j in range(2, i):
            if (i % j != 0): # If number divided by smaller number within range doesn't give a remainder
                flag = True   
            else:
                flag = False 
                break # Get out of loop. Not prime number
        if (flag == True):
            yield i
        i += 2 # Increment i by 2 because even numbers(excluding 2) won't be prime anyway
        
        
        