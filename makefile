CXX = g++
CXXFLAGS = -g -Wall
LIBS_PATH = ./libs
TESTS_PATH = ../date/
EXECUTABLE = lanParty
BUILD_FOLDER_PATH = ../


build:
	cd ./src &&\
	# mkdir $(BUILD_FOLDER_PATH) &&\
	$(CXX) *.c -I$(LIBS_PATH) $(CXXFLAGS) -o $(BUILD_FOLDER_PATH)$(EXECUTABLE)

clean:
	rm -rf ./build/ &&\
	rm -rf ./lanParty
