def convert(m):
    if ":)" in m:
        m = m.replace(":)", "🙂")
    if ":(" in m:
        m = m.replace(":(", "🙁")
    return m

def main():
    message = input("What is your message? ")
    print(convert(message))

main()