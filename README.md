
## About
I wanted to make a menu driven program consisting of all my labwork. Initially I was thinking of going raw with switch case. But turns out switch case is not really "scalable", I needed something that would be SCALABLE. 

I also needed to print "AUTHOR: NAME" before each and every program, which would be super tedious with switch and case. Then I found out about FUCNTION POINTERS. Yes a wrapper function that executes and displays a function would be PERFECT for this job.

I also wanted to learn structers, enumerations, unions and all that good stuff so i decided to include them in my project as well.

## Basic Structre of Program
First the structures, unions and enums:

The enum consists of 4 values RETURN, sub_menu, program and QUIT. It is pretty self explanatory what they are for.
Then the main structure Menu_Item, the heart of the program. It has nested the previously declared enum and a union with alias 'action' which is either a function pointer or Menu_Item pointer. The structure has both the main structure name Menu_Item__tag and alias Menu_Item. This is because the compiler kept freaking out when i used 'struct Menu_Item **menu*'

There is a function main_loop() which basically takes Menu_Item pointer as an argument. The menu items are then displayed. Option is inputted, and a new pointer which was declared is used to hold the pointer to the inputted menu object. 

Then a swtich case statement is used for actions according to the type of the menu object inputted.

Here is where it gets interesting: notice when selected_obj->type == sub_menu, it executes the main_loop() again but where the argument is the sub menu selected. This is basically where the magic happens, nesting using recursion.

With this in mind, to return to the parent menu all you have to do is 'return' the current main_loop() function.
