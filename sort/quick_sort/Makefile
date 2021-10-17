.PHONY:clean run

demo: main.o sort.o
	g++ main.o sort.o -o demo
main.o: main.cpp quick_sort.h sort_helper.h
	g++ -c main.cpp -o main.o
sort.o: quick_sort.cpp quick_sort.h sort_helper.h
	g++ -c quick_sort.cpp -o sort.o

clean:
	rm -r demo
run:
	./demo
