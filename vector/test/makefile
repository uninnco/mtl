vector_test: vector_test.o
	g++ -Wall -o $@  $< -lcpptest -g
test:
	./vector_test > test.html
clean:
	rm -f vector_test.o
	rm -f vector_test
