CC=gcc
CXX=g++
LD=g++
OBJCPY=objcopy

#
# Name of final binary
#
OUTPUT:=output

#
# Paths and folders
#

BIN=./bin/
SRC_C=$(shell find ./src -name "*.c" -printf %p\ )
SRC_CXX=$(shell find ./src -name "*.cpp" -printf %p\ )
OBJ=$(addprefix $(BIN),$(notdir $(patsubst %.c,%.o,$(SRC_C)))) $(addprefix $(BIN),$(notdir $(patsubst %.cpp,%.o,$(SRC_CXX))))
HEADER=$(shell find ./include -name "*.h" -printf %p\ )

INCLUDES =
INCLUDES += -I/usr/include
INCLUDES += -I./include

LIBS = 
LIBS += -lcomplex



LIBSEARCHPATH = 
LIBSEARCHPATH += -L/usr/lib/

#
# Compiler/Linker flags
#
CFLAGS=$(INCLUDES) -pipe -Wall -g -std=gnu99 
CXXFLAGS=$(INCLUDES) -pipe -Wall -g -std=c++11
LDFLAGS=$(LIBSEARCHPATH) $(LIBS)

.PHONY: all clean clean_all print link
.DEFAULT_GOAL:= all



#
# Targets
#
all: link

	
link: $(OBJ)
	@echo "Linking!"
	@$(LD) $(OBJ)  -o $(OUTPUT) $(LDFLAGS)  

test: link
	runtest  --srcdir ./testsuite/ --outdir ./testsuite/log -a
	
print:
	@echo
	@echo "Header files:"
	@echo $(HEADER)
	@echo "C Source files:"
	@echo $(SRC_C)
	@echo "CPP Source files:"
	@echo $(SRC_CXX)
	@echo "Object files:"
	@echo $(OBJ)


clean:
	@-rm -f $(OUTPUT) $(BIN)/*
	
	
#
# Functions
#	
	
#$(call c-one-compile-rule,object_file,source_file)
define c-one-compile-rule
$1: $2 $(HEADER)
	@echo -e " CC\t"	$$<
	@$(CC) $(CFLAGS) -c $$< -o $$@
endef

#$(call c-one-compile-rule,object_file,source_file)
define cxx-one-compile-rule
$1: $2 $(HEADER)
	@echo -e " CC\t"		$$<
	@$(CXX) $(CXXFLAGS) -c $$< -o $$@
endef
 
#$(call c-source-to-object, source_file)
c-source-to-object = $(BIN)$(notdir $(subst .c,.o,$(filter %.c,$1)))

#$(call c-source-to-object, source_file)
cxx-source-to-object = $(BIN)$(notdir $(subst .cpp,.o,$(filter %.cpp,$1)))

#
# Create compile rules
#

$(foreach f, $(SRC_C),$(eval $(call c-one-compile-rule,$(call c-source-to-object,$f),$f)))

$(foreach f, $(SRC_CXX),$(eval $(call cxx-one-compile-rule,$(call cxx-source-to-object,$f),$f)))

