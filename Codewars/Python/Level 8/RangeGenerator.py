# Implement a function named generateRange(min, max, step), which takes three arguments and generates a range of integers from min to max, with the step. The first integer is the minimum value, the second is the maximum of the range and the third is the step. (min < max)

def generate_range(min, max, step):
    # Initialise list
    list_values = []
    for i in range(min, max+1, step): # Add 1 to max for max value to be included
        list_values.append(i) 
    return list_values