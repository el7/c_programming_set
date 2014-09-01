

default: all

all:
	@toilet --gay "c programs"
	
	gcc -std=c99 fibonacci_series.c -o fib.prog
	gcc -std=c99 primes.c -o primes.prog
	gcc -std=c99 bubble_sort.c -o bub_sort.prog
	gcc -std=c99 matrix_mult.c -o matrix_mult.prog			#n
	gcc -std=c99 palindrome.c -o palindrome.prog			#n
	gcc -std=c99 binary_search.c -o bin_search.prog			#n
	gcc -std=c99 singly_linked_list.c -o singly_ll.prog		#n
	gcc -std=c99 doubly_linked_list.c -o doubly_ll.prog		#n
	gcc -std=c99 armstrong_number.c -o arm_numb.prog -lm		
	gcc -std=c99 selection_sort.c -o selection_sort.prog	#n

c: clean

clean:
	@rm -f *.prog


