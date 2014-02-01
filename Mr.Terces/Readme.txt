Mr. Terces is about to perform a secret experiment that generates large amounts of data that
need postprocessing. The postprocessing puts high requirements on how the data is stored in
order to be efﬁcient. Although Mr. Terces can not reveal the details of the experiment, he can
reveal a pseudo code algorithm that deﬁnes the requirements on the data storage:
1. Several million large data items are generated and inserted in the storage space.
2. A key identifying one speciﬁc data item is generated (exactly how is secret). The key item
must be found among all data items in the storage space. To make this search efﬁcient the
storage space must be sorted in ascending order.
3. All data items that were originally inserted after the found item are treated (the details of
this treatment is also secret). This requires the original order of the data items.
4. Repeat from step 2. This loop stops only after several million cycles.
You are asked to help Mr. Terces implement the storage space for all data. Together you
identify how to organize all data items:
1. You need one list or array that keeps the original data item order (insertion order).
2. You need another list or array that sorts the items in ascending order.
3. To conserve memory both lists/arrays must store only pointers to data items.
4. Each data item in the sorted list/array must know it’s position in the other list/array.
Your task is to implement a proof-of-concept data storage that organize the data as described
above. Your proof-of-concept code may simplify irrelevant details. What you need to do is:
• Create a class to represent one data item. The data stored in one item can be simulated by a
normal integer (in reality it may be hundreds of bytes).
• Organize some list(s) or array(s) to represent the data storage. The data storage may be
limited to hold only 10 items in your proof-of-concept code.
• Generate data to ﬁll the storage by simply asking the user for some integers.
• Make sure all data is sorted appropriately.
• Print the sequence in sorted order.
• Ask the user for one number X.
• Find the number X any way you like in the sorted array. (Your ﬁnd does not have to be
efﬁcient. Efﬁciency can be solved later both for sorting and searching.)
• Print all numbers that where inserted after X. Use the array with original insertion order.
You must ﬁnd correct item immediately, without searching or sorting.
• Solve any other issues to get a correct program that is well formatted, well written and does
not leave any memory allocated on exit.