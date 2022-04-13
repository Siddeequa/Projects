# -*- coding: utf-8 -*-
"""
Created on Tue Feb 16 13:15:44 2021

@author: Siddeequa
"""

# Think of an integer between 0 (inc) and 100 (not inc)
# Computer will guess - implement bisection search
# User say whether low or high or correct

# First, ask user to think of a number
print ("Please think of a number between 0 and 100!")

# Computer will guess
low = 0 # Set min guess value
high = 100 # Set max guess value
# Guess using bisection search
guess= int((low + high) / 2) # Middle of low and high

# Show guess to user and ask for validation
# Get user response. h if high, l if low and c if correct
response = input("Is your secret number " + str(guess) + "?\nEnter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly.")

# If guess incorrect
while (response != 'c'):
    if (response == 'h'): 
        # Change high to response
        high = guess # new high
    elif (response == 'l'):
        # Change low to response 
        low = guess # new low
    else: # Invalid user input
        print("\nSorry, I did not understand your input.")
        response = input("Is your secret number " + str(guess) + "?\nEnter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly.")
        continue
    
    # Guess again
    guess = int((low + high) / 2)
    response = input("Is your secret number " + str(guess) + "?\nEnter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly.")

# After exiting loop, that is guess is correct
print("Game over. Your secret number was: " + str(guess))






    
    



