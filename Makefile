BUILD_TOP=.
COMP_BASE_DIR=.
CC=g++

#System libs and build flags
CFLAGS+= -g -DDEBUG_MODULE
CFLAGS+= -DDEBUG_MODULE
LDFLAGS+= 
SYSTEM_LIBS+= -lpthread
DEP_LIB_PATHS+=

#Dependant components and libs
DEP_COMP= 
DEP_LIBS=

#includes
INCLUDES= 	-I/usr/local/include \
			-I$(BUILD_TOP)/include

#Sources
SOURCE_DIR=./
SOURCES= \
		Logger.cpp \
		test_core.cpp

#Objects
OBJECTS=$(SOURCES:.cpp=.o)
OBJECT_DIR=$(COMP_BASE_DIR)/obj
OBJ = $(patsubst %,$(OBJECT_DIR)/%,$(OBJECTS))

#Target Lib
LIB_DIR=$(COMP_BASE_DIR)/lib
LIB=$(LIB_DIR)/libcore.a

#Target Exe
EXE_DIR=$(COMP_BASE_DIR)/bin
EXE=$(EXE_DIR)/testcore

#Start
all:: make_dir $(LIB)

make_dir::
	mkdir -p $(LIB_DIR);
	mkdir -p $(OBJECT_DIR)
	mkdir -p $(EXE_DIR)

exe:: $(EXE)

$(EXE):: $(DEP_LIBS) $(LIB) 
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(DEP_LIB_PATHS) -o $@  $(LIB) $(DEP_LIBS) $(SYSTEM_LIBS)

$(LIB):: $(OBJ)
	$(AR) cr $@ $(OBJ) 

$(DEP_LIBS)::
	@echo "-------------------------------"
	@echo "BUILDING COMPONENTS "
	@echo "-------------------------------"
	@for component in $(DEP_COMP); do \
	echo " "; \
	echo "++ Building $${component}"; \
	$(MAKE) -C $${component}; \
	done

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean::
	rm -f $(OBJ) $(LIB) $(EXE)

clobber::
	@echo "Cleaning every thing..."
	rm -rf $(OBJECT_DIR) $(LIB_DIR) $(EXE_DIR)
	@for component in $(DEP_COMP); do \
	echo " "; \
	echo "++ Cleaning $${component}"; \
	$(MAKE) -C $${component} clobber; \
	done

