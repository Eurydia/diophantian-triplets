# diophantian-triplets
A smalll project about pythagorean (integer) triplets.



```
Pick a function...
    Function (1): Find all possible triplets from one known side length.
    Function (2): Find the third side length from 2 known sides.
    Function (3): Check if a triplets of numbers are sides of a pythagorian triangle.
    Function (4): About this program.
    Function (5): Exit program.

    Let's go with >>
```
There 3 main options
  - Finding two sides from 1 known side.
  - Finding last side from 2 known sides.
  - Verify if a triplets are sides of a pythagorean triangle.


### Option 1:
```
Let's go with >>  1

    -----------------------------
```
First the program will ask you to input the side length that you know.
```
NOTE: Select { -1 } in any field to go back to function selection screen.

Enter your known side length

    Known side length >>  84
```
Then the maximum size length to not go over.
```
Enter the limiting size of side lengths

    Lenght to not exceed >>  9999
```
The result
```
All possible triplet(s) generated from your known side length

13, 84, 85
35, 84, 91
63, 84, 105
80, 84, 116
84, 112, 140
84, 135, 159
84, 187, 205
84, 245, 259
84, 288, 300
84, 437, 445
84, 585, 591
84, 880, 884
84, 1763, 1765

    -----------------------------
```
The result will include every triplets that contains the known side as one of its length.
After outputting the result the programm will run in the same option.
To go back to main menu type in `-1` in ***any*** of the fields.

### Option 2:
```
Let's go with >> 2

    -----------------------------
```
Enter the first side you know
```
NOTE: Select { -1 } in any field to go back to function selection screen.

Enter your known side length

    Known side length >>  19
```
then the second
```
Enter your other known side length

    The other known side length >>  70
```
***Note*** The side lengths you enter does not need to be in order.
The result
```
No possible triplet with given side lengths

    -----------------------------
```

### Option 3
```
Let's go with >>  3

    -----------------------------
```
Enter the first side you know
```
NOTE: Select { -1 } in any field to go back to function selection screen.

Enter your known side length

    Known side length >>  5
```
then the second
```
Enter your other known side length

    Other known side length >>  13
```
then the third
```
Enter your other other known side length

    Other other known side length >>  12
```
The result
```
The council has determined that

 O { 5 }{ 13 }{ 12 } O 

are indeed sides of a pythagorean triangle.

    -----------------------------
```

