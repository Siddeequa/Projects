def main():
    answer = input('What is the answer to the the Great Question of Life, the Universe and Everything? ')
    print(correct(answer.strip(' ')))

def correct(answer):
    return 'Yes' if answer == '42' or answer.lower() == 'forty-two' or answer.lower() == 'forty two' else 'No'

main()