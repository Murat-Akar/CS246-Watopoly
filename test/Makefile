CXX=g++ 
CXXFLAGS=-std=c++20 -Wall -O -g -MMD -Werror=vla # use -MMD to generate dependencies
SOURCES=main.cc Player.cc Square.cc ActionSquare.cc CollectOSAPSquare.cc NeedlesHallSquare.cc CoopFeeSquare.cc GooseNestingSquare.cc GoToTimsSquare.cc SLCSquare.cc TimsLineSquare.cc TuitionSquare.cc PurchasableSquare.cc PropertyData.cc Subject.cc TextObserver.cc GameState.cc # list of all .cc files in your project
OBJECTS=${SOURCES:.cc=.o}  # .o files depend upon .cc files with same names
DEPENDS=${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cc file
EXEC=watopoly_from_makefile

# First target in the makefile is the default target.
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

%.o: %.cc 
	$(CXX) -c -o $@ $< $(CXXFLAGS)

-include ${DEPENDS}

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(DEPENDS) $(EXEC)
