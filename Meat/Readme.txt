Mr. Stig, a market owner, keep track of how long he can recycle meat in his counters. For this, he
have a text file where all meat products are listed together with the number of recycling days. Each
product is on a separate line; name and number of recycling days are separated by a colon. New
products are always added to the end of the file; no order to be expected. Example of file content,
and also of how your program should output results:
Minced beef: 1
Bacon: 7
Filet of beef: 3
Lamb chops: 3
Brisket of beef: 3
Pigs trotters: 2
Filet of pork: 2
Pork chops: 2
...
Mr. Stig realizes that he can make more profit by recycling meat longer, and wants a program for
adjusting the number of recycling days. He also wants to display the data in different ways,
alphabetically or by recycling days. Write a program for Mr. Stig; the program shall do the
following, step-by-step:
1) Take the name of a file and an optional A as a command line argument(s), e.g.
a.out meat.txt
a.out meat.txt A
If option A is given it means that the program shall adjust the recycling days (se 5 below).
The program shall check the argument(s), open the file and check if the file was possible to
open. If anything is wrong an appropriate error message shall be printed and the program shall
then exit.
2) Read the content of the file into a suitable standard container (se what is to be done below), and
store the product name and recycling days in the container.
3) Sort the content of the container by product name, in alphabetic order.
4) Output the content of the now alphabetically ordered container to cout.
5) if option A was given on the command line, the number of recycling days for each product in
the container shall be adjusted. If the number of recycling days
is 1, adjust to 2
is 2, adjust to 4
is greater than 2, adjust by adding 3
6) Reorder the elements in the containerin recycling day order, so products with fewer recycling
days comes before those with more recycling days.
7) Output the now reordered content of the container to cout