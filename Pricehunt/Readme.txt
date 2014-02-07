The website “prisjakt.se” (eng: pricehunt) keep track of the best price for a wide range of
products. It also allow users to rate product in range 1..10. Ratings are shown as a weighted
average. With more user ratings this weighted average approach the true average of all ratings
for that product. If only one single user have rated a product as a 10 (true average 10) the
weighted rating will be 7.5. But if 5 users rated a product as a 10 and 5 users gave the rating 8
(true average 9) the weighted average will be 8.64. Upon inspection of some products and their
ratings you can soon ﬁgure out that the following calculation is used to get the weighted
average from the true average:w=a+((5-a)/(c+1)) wherewis the weighted average, a the true
average and c the number of user ratings. The reverse formula is a=w+(w-5)/c.
In given_ﬁles/prisjakt_mobiltelefoner.txt you have saved the list of mobile phones available on
the site. Each line consist of the product name followed by a single semicolon, then the price in
SEK, the number of user ratings, and ﬁnally the weighted average (or a dash ‘-’ if no ratings
exist). The last three numbers are separated by one or more spaces. Look in the ﬁle to
understand how it is structured.
Your task is to read the ﬁle and print the table again, but add a column with the true average
and remove any lines with fewer than 4 ratings. You may assume that product names are no
longer than 45 characters. You may not keep more than a single line in memory at any given
time during program execution. It must be possible for the user to select any ﬁle without
recompilation of the program.
Output from your program must match given_ﬁles/prisjakt_facit.txt exactly. The three ﬁrst
lines of output:
Samsung Galaxy S4 LTE GT-i9505 16GB 4390:- 85 8.40 8.44
Samsung Galaxy S4 Mini LTE GT-i9195 8GB 2990:- 7 8.47 8.97
Samsung Galaxy S4 Active LTE GT-i9295 16GB 4382:- 6 6.82 7.12
...