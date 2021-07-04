# Given 2 strings, a and b, return a string of the form short+long+short, 
# with the shorter string on the outside and the longer string on the inside. 
# The strings will not be the same length, but they may be empty ( length 0 ). 


def solution(a, b):
    # Get lengths
    len_a = len(a)
    len_b = len(b)
    
    # Ensure strings are of different lengths
    assert len_a != len_b, "Strings are of the same length!"
    
    if len_a > len_b:
        return b + a + b
    else:
        return a + b + a