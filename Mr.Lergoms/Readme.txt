Future game developer of the year Lergnom Raw has come up with a new innovative idea for
the next generation computer game. The title is War World III.
A key element of the new game is the concept of Soldiers combined in Armies. Each soldier
will have different behaviour according to a Strategy. The strategy will form the core of each
soldiers AI.
Lergom has started toying with the implementation of this in given_files/wwiii.cc.
He soon understands that he got off on the wrong foot (see next assignment). He sees that the
implementation of all strategies will end up in a big unmanageable switch in his current
attempt. He wishes to have each strategy nicely packaged in it’s own class instead, but still
uniformly handled by the soldier class (no need to know the speciﬁc strategy to activate it).
Your task in this assignment is to rewrite his ﬁrst attempt to satisfy his wish. You must of
course create suitable subclasses that utilize polymorphism. Your classes must be minimal. Do
not store data you do not need.
Your solution shall produce the same output as Mr. Lergoms solution. As you can understand
the importance in this assignment lies not in output nor functionality, but in how the code
isstructured andwritten.