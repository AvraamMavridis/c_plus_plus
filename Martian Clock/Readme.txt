One day on our neighbour planet Mars is 24 hours, 39 minutes and 35 seconds, or 88775
seconds in earth time. We would however like the martian day to be an exact number of
martian hours, a martian hour to be an exact number of martian minutes and a martian minute
to be an exact number of our normal earth-seconds. It turns out this can be done by deﬁning a
martian minute as 67 earth seconds, a martian hour as 53 martian minutes and a martian day
as 25 martian hours. Convenient (?) and also close in length to our minutes and hours on earth.
Your assignment is to write a program that asks for a martian time of day in the format
“HH:MM:SS” and then prints the martian time one second later. You can presume that the user
always enters the time in the correctform. The output must match the examples below exactly
and in addition you must:

1. use a class to represent the time of day where you use public, private, constructor and
member function(s) appropriately.

2. implement and use the output operator (operator<<) to display the time in one such class.

3. not use excessive enumeration of cases, calculate results algorithmically instead. (In fact,
you do not need any conditions at all.)

Example run 1:
Enter a valid martian time of day: 12:30:40
The martian time one second later: 12:30:41
Example run 2:
Enter a valid martian time of day: 02:45:66
The martian time one second later: 02:46:00
Example run 3:
Enter a valid martian time of day: 15:52:66
The martian time one second later: 16:00:00
Example run 4:
Enter a valid martian time of day: 24:52:66
The martian time one second later: 00:00:00
Example run 5:
Enter a valid martian time of day: 00:00:00
The martian time one second later: 00:00:01 
