LibrarySystem: book.o DVD.o audioCD.o libraryItem.o libraryitems.o patron.o patrons.o loan.o loans.o menus.o main.o
	g++ -o LibrarySystem *.o
book.o: book.cpp book.h
	g++ -c book.cpp
libraryItem.o: libraryItem.cpp libraryItem.h
	g++ -c libraryItem.cpp
libraryitems.o: libraryitems.cpp libraryitems.h libraryItem.h
	g++ -c libraryitems.cpp
patron.o: patron.cpp patron.h
	g++ -c patron.cpp
patrons.o: patrons.cpp patrons.h patron.h
	g++ -c patrons.cpp
loan.o: loan.cpp loan.h
	g++ -c loan.cpp
loans.o: loans.cpp loans.h patrons.h libraryitems.h
	g++ -c loans.cpp
menus.o: menus.cpp loans.h patrons.h libraryitems.h menus.h
	g++ -c menus.cpp
main.o: main.cpp menus.cpp loans.h patrons.h libraryitems.h menus.h
	g++ -c main.cpp
	
run:
	./LibrarySystem
	
clean:
	rm *.o LibrarySystem
	
