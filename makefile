#
#
#


default: all


all: splash complete test not_done
	
	gcc -std=c99 binary_search.c -o bin_search.prog			#n
	gcc -std=c99 armstrong_number.c -o arm_numb.prog -lm		
	gcc -std=c99 selection_sort.c -o selection_sort.prog		#n
	gcc -std=c99 tower_of_hanoi.c -o hanoi.prog
	gcc -std=c99 quick_sort.c -o qsort.prog
	gcc -std=c99 num_of_digits_in_a_number.c -o digits.prog
	gcc -std=c99 is_char_a_vowel.c -o vowel.prog
	gcc -std=c99 perfect_number.c -o perfect_num.prog
	gcc -std=c99 largest_among_n.c -o largest.prog
	gcc -std=c99 leap_year.c -o leap_year.prog


splash:
	@toilet --gay "c programs"


# program works but could be improved
complete:
	gcc -std=c99 deque.c -o deque.prog
	gcc -std=c99 singly_linked_list.c -o singly_ll.prog		
	gcc -std=c99 fibonacci_series.c -o fib.prog
	gcc -std=c99 primes.c -o primes.prog
	gcc -std=c99 bubble_sort.c -o bub_sort.prog

# program does not work and is being tested
test:


clean:
	@rm -f *.prog

not_done:
	gcc -std=c99 doubly_linked_list.c -o doubly_ll.prog		
	gcc -std=c99 palindrome.c -o palindrome.prog			
	gcc -std=c99 matrix_mult.c -o matrix_mult.prog			
