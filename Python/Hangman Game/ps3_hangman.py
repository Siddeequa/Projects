# Hangman game
#

# -----------------------------------
# Helper code
# You don't need to understand this helper code,
# but you will have to know how to use the functions
# (so be sure to read the docstrings!)

import random

WORDLIST_FILENAME = "words.txt"

def loadWords():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    print("  ", len(wordlist), "words loaded.")
    return wordlist

def chooseWord(wordlist):
    """
    wordlist (list): list of words (strings)

    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

# end of helper code
# -----------------------------------

# Load the list of words into the variable wordlist
# so that it can be accessed from anywhere in the program
wordlist = loadWords()

def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    # User has 8 guesses
    # Create list to hold correct letters
    correct_letters = []
     
    # Iterate over letters guessed 
    for letter in lettersGuessed:
        if letter in secretWord:
            correct_letters.append(letter) # Add letter to list of correct letters
            
    # If all correct letters are obtained, lengths of secret word and list would be same
    if (len(secretWord) == len(correct_letters)):
        return True
    else:
        return False
    

def getGuessedWord(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters and underscores that represents
      what letters in secretWord have been guessed so far.
    '''
    # Create list to hold values user has guessed
    guessed_list = []
    
    # First fill guessed_list with underscore to indicate not yet guessed letters
    for i in range(len(secretWord)):
        guessed_list.append("_ ")
    
    # Iterate over letters user has guessed
    for letter in lettersGuessed:
        # Know whether letter is in secret word
        if (letter in secretWord):
            # Iterate over secret word
            for i in range(len(secretWord)):
                # If letter is same as secret word letter at that index
                if (secretWord[i] == letter):
                    guessed_list[i] = letter + " "
                    
    # Convert list into string and return
    return ''.join(guessed_list)
            

def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    import string
    alphabets = string.ascii_lowercase
    
    # Create list to hold remaining alphabets
    remaining_alpha = []
    
    # Iterate over letters in alphabets
    for alpha in alphabets:
        if (alpha not in lettersGuessed):
            remaining_alpha.append(alpha) # Add letter not yet guessed to list
    
    # Convert remaining alphabets list to string and return
    return ''.join(remaining_alpha)
        
        
def hangman(secretWord):
    '''
    secretWord: string, the secret word to guess.

    Starts up an interactive game of Hangman.

    * At the start of the game, let the user know how many 
      letters the secretWord contains.

    * Ask the user to supply one guess (i.e. letter) per round.

    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computers word.

    * After each round, you should also display to the user the 
      partially guessed word so far, as well as letters that the 
      user has not yet guessed.

    Follows the other limitations detailed in the problem write-up.
    '''
    # Print welcome message
    print("Welcome to the game Hangman!")
    
    # State length of word to guess
    length_word = len(secretWord)
    print("I am thinking of a word that is " + str(length_word) + " letters long.")
    print("-----------")
    
    # Create list to hold letters guessed
    letters_user = []
    
    # Number of guesses 
    num_guesses = 8
    
    # Prompt user for guess
    while (num_guesses != 0):
        # State number of guesses
        print("You have " + str(num_guesses) + " guesses left\nAvailable Letters: " + getAvailableLetters(letters_user))
        letter_input = input("Please guess a letter: ")
        # Convert letter to lowercase
        letter_lower = letter_input.lower()
        
        # If letter has already been guessed
        if (letter_lower in letters_user):
            # Repetition of guess
            print("Oops! You've already guessed that letter: " + getGuessedWord(secretWord, letters_user))
            print("-----------")
        else:
            # Add letter to guessed letters list
            letters_user.append(letter_lower)
            if (letter_lower in secretWord): # Correct letter
                print("Good guess: " + getGuessedWord(secretWord, letters_user))
                print("-----------")
                continue
            else:
                # Incorrect guess
                print("Oops! That letter is not in my word: " + getGuessedWord(secretWord, letters_user))
                print("-----------")
                # User loses a guess
                num_guesses -= 1
            # If word has been guessed
        res = isWordGuessed(secretWord, letters_user)
        if (res == True):
            break
        else: 
            continue
    
    # If broke out of loop after number of guesses has exhausted, user loses
    if (num_guesses == 0):
        print("Sorry, you ran out of guesses. The word was " + secretWord)
    else:
        # If broke out of loop through break, user wins
        print("Congratulations, you won!")
   
        


 


# When you've completed your hangman function, uncomment these two lines
# and run this file to test! (hint: you might want to pick your own
# secretWord while you're testing)

secretWord = chooseWord(wordlist).lower()
hangman(secretWord)
