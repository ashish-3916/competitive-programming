/*
Self-Balancing is provided by painting each node with one two colors(Red or Black).
Red Black Trees provide faster insertion and removal operations than AVL trees as
fewer rotations are done due to relatively relaxed balancing.

Root is always black.
All NULL leaves are black, both children of red node are black.
Every simple path from a given node to any of its descendant leaves contains the same number of black
nodes.
Path form root to farthest leaf is no more than twice as long as path from root to nearest leaf.
*/


// Perform standard BST insertion and make the colour of newly inserted nodes as RED.
// If x is the root, change the colour of x as BLACK (Black height of complete tree increases by 1).
// Do the following if the color of x’s parent is not BLACK and x is not the root. 
// a) If x’s uncle is RED (Grandparent must have been black from property 4) 
// (i) Change the colour of parent and uncle as BLACK. 
// (ii) Colour of a grandparent as RED. 
// (iii) Change x = x’s grandparent, repeat steps 2 and 3 for new x. 
// 
//b) If x’s uncle is BLACK, then there can be four configurations for x, x’s parent (p) and x’s grandparent (g) (This is similar to AVL Tree) 
// (i) Left Left Case (p is left child of g and x is left child of p) 
// (ii) Left Right Case (p is left child of g and x is the right child of p) 
// (iii) Right Right Case (Mirror of case i) 
// (iv) Right Left Case (Mirror of case ii)
