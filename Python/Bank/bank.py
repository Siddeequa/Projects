def main():
    greeting = input("Greeting? ")
    print(result(greeting.lstrip(" ").lower()))

def result(greeting):
    return "$0" if greeting[0:5] == "hello" else "$20" if greeting[0] == "h" else "$100"

main()
