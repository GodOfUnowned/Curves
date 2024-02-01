ROOT_DIR=..

LIBCURVES_SRC=point.cpp circle.cpp ellipse.cpp helix.cpp
LIBCURVES_OBJ=$(LIBCURVES_SRC:.cpp=.o)
LIBCURVES=libcurves.so

CXX=g++
CXX_FLAGS=-O2 -Wall -I${ROOT_DIR}/include -std=c++20

all: $(LIBCURVES) main

$(LIBCURVES): $(LIBCURVES_OBJ)
	$(CXX) $(CXX_FLAGS) -fpic -shared $(LIBCURVES_OBJ) -o ${ROOT_DIR}/${LIBCURVES}

$(LIBCURVES_OBJ): $(LIBCURVES_SRC)
	$(CXX) $(CXX_FLAGS) -fpic -c $(LIBCURVES_SRC)

main: $(LIBCURVES) main.cpp
	$(CXX) main.cpp -o $(ROOT_DIR)/curves $(CXX_FLAGS) -L${ROOT_DIR}/ -lcurves -Wl,-rpath=./

clean:
	rm -rf *.o

