# Push_Swap_V02
This project is a task given where i am supposed to do a number sorting algorithm to sort numbers.


	██▓███   █    ██   ██████  ██░ ██   ██████  █     █░ ▄▄▄       ██▓███  
	▓██░  ██▒ ██  ▓██▒▒██    ▒ ▓██░ ██▒▒██    ▒ ▓█░ █ ░█░▒████▄    ▓██░  ██▒
	▓██░ ██▓▒▓██  ▒██░░ ▓██▄   ▒██▀▀██░░ ▓██▄   ▒█░ █ ░█ ▒██  ▀█▄  ▓██░ ██▓▒
	▒██▄█▓▒ ▒▓▓█  ░██░  ▒   ██▒░▓█ ░██   ▒   ██▒░█░ █ ░█ ░██▄▄▄▄██ ▒██▄█▓▒ ▒
	▒██▒ ░  ░▒▒█████▓ ▒██████▒▒░▓█▒░██▓▒██████▒▒░░██▒██▓  ▓█   ▓██▒▒██▒ ░  ░
	▒▓▒░ ░  ░░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒▒ ▒▓▒ ▒ ░░ ▓░▒ ▒   ▒▒   ▓▒█░▒▓▒░ ░  ░
	░▒ ░     ░░▒░ ░ ░ ░ ░▒  ░ ░ ▒ ░▒░ ░░ ░▒  ░ ░  ▒ ░ ░    ▒   ▒▒ ░░▒ ░     
	░░        ░░░ ░ ░ ░  ░  ░   ░  ░░ ░░  ░  ░    ░   ░    ░   ▒   ░░       
				░           ░   ░  ░  ░      ░      ░          ░  ░         
																			


The Push swap project is a simple yet highly structured algorithmic challenge: you need to sort data. You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks. Your goal? Write a C program called push_swap that calculates and displays the shortest sequence of Push_swap instructions needed to sort the given integers. Easy.

You have 2 stacks named a and b.
 • At the beginning: 
 		◦ The stack a contains a random number of unique negative and/or positive integers.
		◦ The stack b is empty. • The goal is to sort the numbers in stack a in ascending order.
 To achieve this, you have the following operations at your disposal:
 	sa (swap a): Swap the first 2 elements at the top of stack a.
	 			 Do nothing if there is only one element or none. 
	sb (swap b): Swap the first 2 elements at the top of stack b.
				 Do nothing if there is only one element or none. 
	ss : sa and sb at the same time.
	
	pa (push a): Take the first element at the top of b and put it at the top of a.
				 Do nothing if b is empty.
	pb (push b): Take the first element at the top of a and put it at the top of b.
				Do nothing if a is empty.
	ra (rotate a): Shift up all elements of stack a by 1.
				The first element becomes the last one. 
	rb (rotate b): Shift up all elements of stack b by 1.
				 The first element becomes the last one.
	rr : ra and rb at the same time. 
	rra (reverse rotate a): Shift down all elements of stack a by 1.
			 The last element becomes the first one. 
	rrb (reverse rotate b): Shift down all elements of stack b by 1.
				The last element becomes the first one. 
	rrr : rra and rrb at the same time.

my type, what is priyas type-> gently, soft character, Playlist, the way i treat her. 

