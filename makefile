#

default: all

all: splash complete test

splash:
	@toilet --gay "c programs"


## program works (potentially well) but could be improved
complete:
	gcc -std=c99 fibonacci_series.c -o fib.prog
	gcc -std=c99 armstrong_number.c -o arm_numb.prog -lm		
	gcc -std=c99 selection_sort.c -o selection_sort.prog		
	gcc -std=c99 num_of_digits_in_a_number.c -o digits.prog
	gcc -std=c99 is_char_a_vowel.c -o vowel.prog
	gcc -std=c99 perfect_number.c -o perfect_num.prog
	gcc -std=c99 largest_among_n.c -o largest.prog
	gcc -std=c99 leap_year.c -o leap_year.prog
	gcc -std=c99 primes.c -o primes.prog
	gcc -std=c99 bubble_sort.c -o bub_sort.prog
	gcc -std=c99 factorial.c -o fact.prog
	gcc -std=c99 tower_of_hanoi.c -o hanoi.prog


## program is being tested
test:



## in progress, near or far from done
not_done:
	gcc -std=c99 singly_linked_list.c -o singly_ll.prog		
	gcc -std=c99 deque.c -o deque.prog
	gcc -std=c99 binary_search.c -o bin_search.prog			
	gcc -std=c99 quick_sort.c -o qsort.prog
	gcc -std=c99 doubly_linked_list.c -o doubly_ll.prog		
	gcc -std=c99 palindrome.c -o palindrome.prog			
	gcc -std=c99 matrix_mult.c -o matrix_mult.prog			


## will do these after others are done
questionable:	
	addition_deleting_edges_verticies_graph.c
	add_without_ADD.c
	adj_matrix.c
	AVL_insertion.c
	binary_search_recurs.c
	BST_ins_del.c
	circular_deque.c
	circularly_linked_list.c
	copy_the_string.c
	even_odd.c
	file_IO.c
	floyd_triangle.c
	full_in-threaded_BST_ins_del_trav.c
	heap_ins_del.c
	heap_sort.c
	insertion_sort.c
	linear_search.c
	linear_search_recurs.c
	malloc.c
	merge_sort.c
	pascal_triangle.c
	polynomial.c
	power_of_given.c
	prims_alg.c
	queue_using array.c
	queue_using_ll.c
	quick_sort_recurs.c
	radix_sort.c
	random_num_gen.c
	reverse_linked_list.c
	reverse_number.c
	reverse_string_using_stack.c
	shell_sort.c
	sorted_linked_list.c
	sparse_matrix.c
	stack_using_ll.c
	star_triangle.c
	string_comp.c
	strongs_numbers.c
	subtract_without_SUB.c
	sum_of_dig.c
	swap_numbers.c
	swap_string.c
	swap_without_third_var.c
	traversing_graph_through_DFS_BFS.c
	warshalls_alg.c


clean:
	@rm -f *.prog



