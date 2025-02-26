## [X] PARSING DOUBLE LINKED LIST

[x] Create a Makefile that compiles with Libft 
[x] Receive the elements
[x] Create struct of program
[x] Convert str to numbers
[x] Add them to a circular linked list of program
[x] Convert the numbers to rank : 0, 1, 2, 3
	PSEUDOCODE
	- Faire une loop sur la totalite de la liste B.
	a chaque nombre de la liste, compter le nombre de nombre en dessous du nombre actuel. cet indice sera ajoute a la liste A. 
	Free la liste B.

## [X] Check for errors

[x] If one of the values is not a number, add error message "Error\n"
[x] If one of the values is a duplicate, add error message "Error\n"
[x] Check if any number is bigger or small than an int
[x] Switch to write to send errors to fd 2
[ ] exit(exit_failure) -> take care of leaks

## Make each of the commands work

[ ] sa: Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
[ ] sb: Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
[ ] ss : sa and sb at the same time.
[ ] pa: Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
[ ] pb: Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
[ ] ra: Shift up all elements of stack a by 1.
	The first element becomes the last one.
[ ] rb: Shift up all elements of stack b by 1.
	The first element becomes the last one.
[ ] rr: ra and rb at the same time.
[ ] rra: Shift down all elements of stack a by 1.
	The last element becomes the first one.
[ ]	rrb: Shift down all elements of stack b by 1.
	The last element becomes the first one.
[ ] rrr : rra and rrb at the same time.

## ALGORITHM

[ ] Look into algorithms
[ ] Add visualizer : https://github.com/o-reo/push_swap_visualizer
[ ] Add checker
[ ] look into alogrithm complexity
[ ] Find the most common algorithms
[ ] Implement the algorithm

- Radix Sort : https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

Sorting based on each digit. You first need to rank them
Then sort in base of 2 for 2 bo es using bits

- Sillicon valley lady : https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

cases for 3, 5 100, 500.

- The mechanical turk : https://medium.com/@ayogun/push-swap-c1f5d2d41e97

Sending 2 numbers from stack A to stack B
Then send the cheapest number first, in the 


- The Korean

## ALGORITHM BREAKDOWN

[ ] Check if sorted function
[ ] Count number of elements in dblklist
[ ] 3 numbers sort
[ ] Create view 2 stacks function
[ ] add asc and desc value to struct
[ ] Create function that will add logic value to asc and desc
[ ] Create logic loop
[ ] Add logic to send to B until 3
[ ] add logic to send to A
[ ] optimize
[ ] clean
[ ] Make sure to keep the logic unmoved if already sorted



[ ] update atoi to check for INT_MAX before nbr * 10
[ ] if empty tring