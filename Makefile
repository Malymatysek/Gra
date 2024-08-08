#
# 'make'        build executable file 'main'
# 'make clean'  removes all .o and executable files
#

# define the Cpp compiler to use
CXX = g++

# define any compile-time flags
CXXFLAGS	:= -std=c++17 -Wall -Wextra -g

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = 

# define output directory
OUTPUT	:= output

# define source directory
SRC		:= src

# define test source directory
TEST	:= tests

# define include directory
INCLUDE	:= include

# define lib directory
LIB		:= lib

ifeq ($(OS),Windows_NT)
MAIN	:= main.exe
TESTOUT := test.exe
SOURCEDIRS	:= $(SRC)
TESTDIRS 	:= $(TEST)
LIBDIRS		:= $(LIB)
FIXPATH = $(subst /,\,$1)
RM			:= del /q /f
MD	:= mkdir
else
MAIN	:= main 
TESTOUT := test
SOURCEDIRS	:= $(shell find $(SRC) -type d)
TESTDIRS 	:= $(shell find $(TEST) -type d)
INCLUDEDIRS := $(shell find $(INCLUDE) -type d) $(GOOGLETEST)
LIBDIRS		:= $(shell find $(LIB) -type d)
FIXPATH = $1
RM = rm -f
MD	:= mkdir -p
endif

# define any directories containing header files other than /usr/include
INCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%)) 

# define the C libs
LIBS		:= $(patsubst %,-L%, $(LIBDIRS:%/=%)) 

# define the C source files
SOURCES		 := $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))
TEST_SOURCES := $(wildcard $(patsubst %,%/*.cpp, $(TESTDIRS)))
# define the C object files
OBJECTS		 := $(SOURCES:.cpp=.o)
TEST_OBJECTS := $(TEST_SOURCES:.cpp=.o)
# define the dependency output files
DEPS		:= $(OBJECTS:.o=.d)
TEST_DEPS   := $(TEST_OBJECTS:.o=.d)
#
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

OUTPUTMAIN	:= $(call FIXPATH,$(OUTPUT)/$(MAIN))
OUTPUTTEST	:= $(call FIXPATH,$(OUTPUT)/$(TESTOUT))

all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

$(OUTPUT):
	$(MD) $(OUTPUT)

$(MAIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS) $(LIBS)

$(TESTOUT): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTTEST) $(TEST_OBJECTS) $(OBJECTS) $(LFLAGS) $(LIBS)

# include all .d files
-include $(DEPS)
-include $(TEST_DEPS)
# this is a suffix replacement rule for building .o's and .d's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# -MMD generates dependency output files same name as the .o file
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -MMD $<  -o $@

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(OUTPUTTEST)
	$(RM) $(call FIXPATH,$(OBJECTS))
	$(RM) $(call FIXPATH,$(TEST_OBJECTS))
	$(RM) $(call FIXPATH,$(DEPS))
	$(RM) $(call FIXPATH,$(TEST_DEPS))
	@echo Cleanup complete!

run: $(MAIN)
	./$(OUTPUTMAIN)
	@echo Executing 'run' complete!

test: $(TESTOUT)
	./$(OUTPUTTEST)
	@echo Executing 'test' complete!