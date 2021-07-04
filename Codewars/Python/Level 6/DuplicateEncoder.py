# The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character appears only once in the original string, 
# or ")" if that character appears more than once in the original string. 
# Ignore capitalization when determining if a character is a duplicate.


def duplicate_encode(word):
    # List to hold new string characters
    new_string = []
    # Convert word to lowercase to facilitate comparison of characters
    new_word = word.lower()
    # Iterate over word
    for char in new_word:
        # Initialise character count
        # If character appears only once, count will be one. Else, more than 1
        count = 0
        # Iterate over word again to check against other characters
        for test_char in new_word:
            if char == test_char: # If they are the same
                count += 1 
        # Check whether word has duplicates of that character
        if count > 1:
            new_string.append(")")
        else:
            new_string.append("(")
    # Convert ist to string and return
    return "".join(new_string)