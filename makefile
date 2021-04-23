CXX = g++
CXXFLAGS = -Wall

proj4: Farm.o AgItem.o Vegetable.o Animal.o Tree.o Fruit.o proj4.cpp
	$(CXX) $(CXXFLAGS) Farm.o AgItem.o Vegetable.o Animal.o Tree.o Fruit.o proj4.cpp -o proj4

Farm.o: AgItem.cpp Vegetable.cpp Animal.cpp Tree.cpp Farm.cpp Fruit.cpp Farm.h
	$(CXX) $(CXXFLAGS) -c Farm.cpp

Vegetable.o: AgItem.cpp Vegetable.cpp Vegetable.h
	$(CXX) $(CXXFLAGS) -c Vegetable.cpp

Animal.o: AgItem.cpp Animal.cpp Animal.h
	$(CXX) $(CXXFLAGS) -c Animal.cpp

Tree.o: AgItem.cpp Fruit.cpp Tree.cpp Tree.h
	$(CXX) $(CXXFLAGS) -c Tree.cpp

AgItem.o: AgItem.cpp AgItem.h
	$(CXX) $(CXXFLAGS) -c AgItem.cpp

Fruit.o: Fruit.cpp Fruit.h
	$(CXX) $(CXXFLAGS) -c Fruit.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./proj4