def main():
    time = convert(input("What is the time? "))
    if 7 <= time <= 8:
        print("breakfast time")
    elif 12 <= time <= 13:
        print("lunch time")
    elif 18 <= time <= 19:
        print("dinner time")


def convert(time):
    hrs, min = time.split(":")
    return round(int(hrs)+int(min)/60, 2)


if __name__ == "__main__":
    main()