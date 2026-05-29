# Vehicle Registration System using Binary Search Tree (BST)

## Application of Trees (BST)

---

# Scenario

A Vehicle Registration System stores vehicle records using a Binary Search Tree.

* New vehicle registration → Insert into BST
* Display vehicle records → Inorder Traversal
* Delete vehicle record → Delete Operation

BST helps in maintaining vehicle numbers in sorted order and allows fast searching, insertion, and deletion.

---

# Justification

Binary Search Tree is used because:

* It stores vehicle numbers in sorted order automatically.
* Searching is faster compared to linear search.
* Efficient for dynamic records where vehicles are frequently added or removed.

## Traversals Provide Organized Outputs

* Inorder → Displays vehicle numbers in ascending order
* Preorder → Useful for backup
* Postorder → Useful for deletion/freeing memory

---

# Algorithm

## 1. Insert Vehicle

1. Create a new vehicle node.
2. If root is NULL, make new node the root.
3. Compare vehicle number:

   * Smaller → move left
   * Larger → move right
4. Repeat until empty position is found.
5. Insert the node.

---

## 2. Inorder Traversal (LNR)

1. Traverse left subtree.
2. Visit root.
3. Traverse right subtree.

---

## 3. Preorder Traversal (NLR)

1. Visit root.
2. Traverse left subtree.
3. Traverse right subtree.

---

## 4. Postorder Traversal (LRN)

1. Traverse left subtree.
2. Traverse right subtree.
3. Visit root.

---

## 5. Delete Vehicle

1. Search the vehicle number.

### Cases

* Leaf node → delete directly
* One child → replace with child
* Two children → replace using inorder successor

---

# Time Complexity

| Operation           | Time Complexity |
| ------------------- | --------------- |
| Insert              | O(log n)        |
| Delete              | O(log n)        |
| Search              | O(log n)        |
| Inorder Traversal   | O(n)            |
| Preorder Traversal  | O(n)            |
| Postorder Traversal | O(n)            |

---

# Technologies Used

* C Programming
* Binary Search Tree (BST)
* Dynamic Memory Allocation

---

# Features

* Add Vehicle Records
* Delete Vehicle Records
* Display Vehicles in Sorted Order
* Tree Traversals
* Beginner Friendly Implementation

---

# CODE

For code refer BST vehiclereg file.
