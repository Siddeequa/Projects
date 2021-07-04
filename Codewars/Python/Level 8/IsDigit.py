# Given a string s, write a method (function) that will return true if its a valid single integer or floating number or false if its not.


def isDigit(string):
    # Convert to float if possible
    try:
        float(string)
        return True # If successfully converted to float, it means it was either already a float or was an integer
    except: # Will jumo to except block if didn't manage to convert to float. Meaning another data type
        return False