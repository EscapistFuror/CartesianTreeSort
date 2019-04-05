Cartesian Tree Sorting Algorithm

About: 
    
        -> Cartesian Sort is an Adaptive Sorting Technique.
        -> When a list is already partially sorted, Cartesian Sort takes advantage of this and reduces the time complexity of sorting.
        -> It gives best result of O(n). Cartesian tree is a min heap.
        -> It is not a height balanced tree but follows the rule that all the children of a perticular node in the tree have greater value than the node value.

Technology : Implemented in C++. Used STL. Data Structures like Priority Queue and Array were used.

Functions:

            1. Structure: Node -> To Create node for our tree. Contains Data, Left Child pointer and Right Child pointer.
            2. pQBasedTraversal -> Uses Priority Queue to inorder traverse the fully sorted tree.
            3. makeCartesianTree -> Initializes Parent array,Left Child array, Right Child array and updates them according to the given array of elements.
            4. buildCartesianTree -> Add nodes to the tree to build the cartesian tree with the help of Left Child, Right Child and Parent array.
            5. main -> To run the program.
                        
