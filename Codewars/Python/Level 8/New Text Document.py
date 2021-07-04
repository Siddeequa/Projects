# Create a function called shortcut to remove all the lowercase vowels in a given string.

def shortcut( s ):
    # List of lowercase vowels
    vowels_lower = ['a', 'e', 'i', 'o', 'u']
    # New string to hold s without lowercase vowels
    new_s = ''
    # Iterate over characters in s
    for character in s:
        # If character is not present in defined list of lowercase vowels
        if character not in vowels_lower:
            new_s += character # Add to new string
    return new_s