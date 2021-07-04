# Remove a exclamation mark from the end of string. 
# For a beginner kata, you can assume that the input data is always a string, no need to verify it.

def remove(s):
    # Ensure s is a string
    assert type(s) == type("abc"), "Argument is not a string"
    
    if s == "": # In case string is empty
        return ""
    if len(s) == 1 and s == "!": # If string comprises only an exclamation mark
        return None # there will be nothing left
    elif s[-1] == "!": # get last element
        return s[:-1] # Return everything but the last element
    else:
        return s # If no exclamation mark at the end, return whole string