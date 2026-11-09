all: bin/testListLinked bin/testPoint2D bin/testCircle bin/testRectangl bin/testSquare bin/testDrawing

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

# Reglas para Rectangle
Rectangle.o: Rectangle.cpp Rectangle.h Shape.h Point2D.h
	g++ -c Rectangle.cpp

bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	g++ -c testRectangle.cpp
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o

# Reglas para Square
Square.o: Square.cpp Square.h Rectangle.h Shape.h Point2D.h
	g++ -c Square.cpp


bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o
	g++ -c testSquare.cpp
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Square.o Rectangle.o Shape.o Point2D.o

#Reglas para Drawing
Drawing.o: Drawing.cpp Drawing.h List.h ListArray.h Shape.h Circle.h Square.h
	g++ -c Drawing.cpp

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	g++ -c testDrawing.cpp
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.o Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o

# Limpieza de temporales y binarios
clean:
	rm -rf *.o *.gch *.pch bin

.PHONY: all clean
