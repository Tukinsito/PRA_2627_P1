all: bin/testListLinked bin/testPoint2D bin/testCircle

# Reglas para la EDL (Lista enlazada y nodos)
bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp

# Reglas para Point2D
Point2D.o: Point2D.cpp Point2D.h
	g++ -c Point2D.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

# Reglas para Shape
Shape.o: Shape.cpp Shape.h Point2D.h
	g++ -c Shape.cpp

# Reglas para Circle
Circle.o: Circle.cpp Circle.h Shape.h Point2D.h
	g++ -c Circle.cpp

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o

# Limpieza de temporales y binarios
clean:
	rm -rf *.o *.gch *.pch bin

.PHONY: all clean
