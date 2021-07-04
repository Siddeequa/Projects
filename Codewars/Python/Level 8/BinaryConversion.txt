# Given a non-negative integer n, write a function to_binary/ToBinary which returns that number in a binary format.

def to_binary(n):
    """
        Takes a non-negative integer and converts it in its binary format.
        
        n: int, a positive integer
        
        returns: binary format of the number
    """
    # Decimal to Binary conversion
    # Divide number by 2
    # Note that remainder - either 0 or 1
    # Number in binary form is the remainders in reverse order
    
    # string to hold remainders
    remainder = ""
    
    while n != 0:
        rem = str(n % 2)
        remainder += rem # add remainder to complete remainder string
        n //= 2 # Divide n by 2
    
    return int(remainder[::-1]) # Reverse string and cast back to int