CC=g++ -g -lrt -lpthread

LIB=$(patsubst ../core/lib/%.cpp,  ../core/bin/%.o, $(wildcard ../core/lib/*.cpp))
OBJECTS=$(LIB:.cpp=.o)
TESTS=$(wildcard *.cpp)

default: clean $(TESTS)

$(TESTS): $(OBJECTS)
	$(CC) $@ $(OBJECTS) -o $(patsubst %.cpp,%,$@) 

$(OBJECTS):
	$(CC) -c -o $@ $(patsubst ../core/bin/%.o,  ../core/lib/%.cpp, $@) 

clean:
	$(RM) $(OBJECTS) *.o 
