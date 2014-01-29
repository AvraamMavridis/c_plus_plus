Lergom in the previous assignment was said to “be off on the wrong foot”. That is of course a
phrase for “starting out the wrong way”. It turns out a list of more phrases and idioms are
available in given_files/phrases.txt (from www.goenglish.com). The ﬁle has
groups of lines in which the ﬁrst line contain a phrase and the next few lines uses that phrase in
a context in order to explain the phrase. The last line in each group is empty.
Functional requirements
Write a program that uses the ﬁle to explain phrases. Ask for a keyword and ﬁnd all phrases
containing that keyword. Print the example of how to use each found phrase. The default ﬁle to
open is given_files/phrases.txt, and if you fail to open that ﬁle you must ask the
user for a new ﬁle until the user enters a valid ﬁle. Examples below describe how your program
must work. You do not have to consider upper/lower case differences.
Non-functional requirements and presumptions
1. You may only open the ﬁle once (you may seek in the ﬁle). You may fail to open the ﬁle any
number of times.
2. You may not presume a ﬁxed number of phrases, the ﬁle will grow beyond your
presumption or another ﬁle will contain more phrases than your presumption.
3. You may (but need not) store the entire ﬁle content in memory, but you must in that case
carefully observe requirement number 2 just above this.
4. You may presume that each line is shorter than 1000 characters.
Examples running the program three times
________________________________________________________________________
Enter a keyword of the phrase to explain: hand
----
A bird in the hand is worth two in the bush
- "Dan has asked me to go party with him. What if my boyfriend finds out?"
- "Don’t go. A bird in the hand is worth two in the bush."
----
Never bite the hand that feeds you
- "We have been your best customers for years. How could you suddenly
treat us so rudely? You should never bite the hand that feeds you."
________________________________________________________________________
Enter a keyword of the phrase to explain: dozen
----
A dime a dozen
- "I don’t need friends like him; they are a dime a dozen."
________________________________________________________________________
Enter a keyword of the phrase to explain: safe
----
Better safe than sorry
- "Should I bring my umbrella?"
- "Better safe than sorry."
- "Okay. I’ll go get it.