2013.4.26

Today, when I coded the data stucture- Stack, I find the usefulness of Template in c++.
Cause without Template, 
I have to specify the datatype to be stored in the stack, for 
instance in this case, the stack stores the node 
of the tree, next time if I have another
datatype need being DFS, I have to modify my stack class again in order 
for it to be 
usable.  What a depressing situation.

2013.4.27
Today, when I add both queue and stack into my code, when I compile binary search tree using both BFS and DFS,
it has a problem, as both queue.h and stack.h contains node.h, thus it's a duplicated declaration, I searched
the web and found out that I only need to add an so-called Included Guard for node.h(the most frequently used
class), the problem is resolved.