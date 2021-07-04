# Square every digit of a number and concatenate them.

# For example, if we run 9119 through the function, 811181 will come out, 
# because 92 is 81 and 12 is 1.

# Note: The function accepts an integer and returns an integer

def square_digits(num):
    # Ensure arg is an integer
    assert type(num) == type(1), "Argument is not an integer"
    
    # Concatenated string
    concat_string = ''
    
    # If num is 0, just return zero (zero squared is zero)
    if num == 0:
        return 0
    
    #Else
    # Get each digit of number one by one
    # Get last digit by using modulus operator
    while (num != 0):
        digit = num % 10 # Get last digit
        num = num // 10 # Remove last digit from num
        
        # Add squared number to string
        concat_string = str(digit**2) + concat_string 
    
    # Cast string to int and return
    return int(concat_string) 