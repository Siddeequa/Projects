# Home Federal Savings Bank Greeting Policy

In season 7, episode 24 of Seinfeld, Kramer visits a bank that promises to give $100 to anyone who isn’t greeted with a “hello.” 
Kramer is instead greeted with a “hey,” which he insists isn’t a “hello,” and so he asks for $100. 
The bank’s manager proposes a compromise: “You got a greeting that starts with an ‘h,’ how does $20 sound?” Kramer accepts.


## The program: 

* The user is prompted for a greeting. 
* If the greeting starts with “hello”, $0 is outputted. If the greeting starts with an “h”, $20 is outputted. 
* Otherwise, $100 is outputted. 
* Any leading whitespace in the user’s greeting is ignored and the user’s greeting is greeted case-insensitively.

**DEMO:**


```bash
$ python bank.py
Greeting: Hello, Newman
$0
$ python bank.py
Greeting: Hey
$20
$ python bank.py
Greeting: What's up?
$100
```
