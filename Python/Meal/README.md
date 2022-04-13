# Meal Time

Suppose that you’re in a country where it’s customary to eat breakfast between 7:00 and 8:00, lunch between 12:00 and 13:00, and dinner between 18:00 and 19:00. 
Wouldn’t it be nice if you had a program that could tell you what to eat when?


## The Program:

* The user is prompted for a time.
* It is outputted whether it’s breakfast time, lunch time, or dinner time.
* If it’s not time for a meal, nothing is outputted. 
* It is assumed that the user’s input will be formatted in 24-hour time as #:## or ##:##. 
* It is assumed that each meal’s time range is inclusive. For instance, whether it’s 7:00, 7:01, 7:59, or 8:00, or anytime in between, it’s time for breakfast.  

**DEMO:**

```
$ python meal.py
What is the time? 7:30
breakfast time
$ python meal.py
What is the time? 18:59
dinner time
```
