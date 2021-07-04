# Make a function that returns the value multiplied by 50 and increased by 6. If the value entered is a string it should return "Error".

def problem(a):
    # check whether parameter is a string first
    if type(a) == type("a"):
        return "Error"
    # if not string
    return (a * 50) + 6