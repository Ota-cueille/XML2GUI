## VARIABLES ##
CXX = g++
EXEC = program

# Configuration
RELEASE_DIR = release
RELEASE_EXEC = $(RELEASE_DIR)/$(EXEC)
DEBUG_DIR = debug
DEBUG_EXEC = $(DEBUG_DIR)/$(addsuffix -debug, $(EXEC))

# DIRECTORIES
ifndef SRC_CPP
	SRC_CPP = src/*.cpp

	SRC_CPP += W:/c++/libs/glad/src/glad.cpp
	
	SRC_CPP += $(wildcard W:/c++/libs/glfw-3.3.4/src/*.cpp)
	
	SRC_CPP += $(wildcard W:/c++/libs/imgui/*.cpp)
	SRC_CPP += $(wildcard W:/c++/libs/imgui/misc/cpp/*.cpp)
	SRC_CPP += W:/c++/libs/imgui/backends/imgui_impl_glfw.cpp
	SRC_CPP += W:/c++/libs/imgui/backends/imgui_impl_opengl3.cpp
endif

INCLUDE_DIR = -I include

RELEASE_OBJS_DIR = $(RELEASE_DIR)/OBJ
DEBUG_OBJS_DIR = $(DEBUG_DIR)/OBJ

DEBUG_FLAGS = -g
CXX_FLAGS = -std=c++2a
RELEASE_FLAGS = -static -static-libgcc -static-libstdc++ -O3

LIBS = -L "W:/c++/libs/glfw-3.3.4/bin" -lglfw3 -lopengl32 -lgdi32 -limm32

INCLUDE_DIR += -I W:/c++/libs/boost_1_74_0
INCLUDE_DIR += -I W:/c++/libs/glfw-3.3.4/include
INCLUDE_DIR += -I W:/c++/libs/glad/include
INCLUDE_DIR += -I W:/c++/libs/imgui
INCLUDE_DIR += -I W:/c++/libs/imgui/backends
INCLUDE_DIR += -I W:/c++/libs/imgui/misc/cpp

## DEPENDENCIES ##

all: debug release
re: clean debug release

red: cleand debug
rer: cleanr release

exe:
	@./$(RELEASE_EXEC)

# Release
release: $(RELEASE_EXEC)

$(RELEASE_EXEC):
	@for file in $(SRC_CPP) ; do \
        make --no-print-directory compile_release SRC_CPP=$$file ; \
    done
	$(CXX) $(CXX_FLAGS) $(RELEASE_FLAGS) -o $@ $(RELEASE_OBJS_DIR)/*.o $(LIBS)

COMPILE_RELEASE = $(SRC_CPP:$(SRC_CPP)=$(RELEASE_OBJS_DIR)/$(patsubst %.cpp,%.o,$(lastword $(subst /, ,$(SRC_CPP)))))

compile_release: $(COMPILE_RELEASE)

$(RELEASE_OBJS_DIR)/%.o:$(SRC_CPP)
	$(CXX) $(CXX_FLAGS) -o $@ -c $< $(INCLUDE_DIR) $(LIBS)

# Debug
debug: $(DEBUG_EXEC)

$(DEBUG_EXEC):
	@for file in $(SRC_CPP) ; do \
        make --no-print-directory compile_debug SRC_CPP=$$file ; \
    done
	$(CXX) $(CXX_FLAGS) -o $@ $(DEBUG_OBJS_DIR)/*.o $(LIBS)

COMPILE_DEBUG = $(SRC_CPP:$(SRC_CPP)=$(DEBUG_OBJS_DIR)/$(patsubst %.cpp,%.o,$(lastword $(subst /, ,$(SRC_CPP)))))

compile_debug: $(COMPILE_DEBUG)

$(DEBUG_OBJS_DIR)/%.o:$(SRC_CPP)
	$(CXX) $(CXX_FLAGS) $(DEBUG_FLAGS) -o $@ -c $< $(INCLUDE_DIR) $(LIBS)

# Delete directories
delete: deleter deleted

deleter:
	rm -r $(RELEASE_DIR)

deleted:
	rm -r $(DEBUG_DIR)

# Clean files
clean: cleanr cleand

cleanr:
	rm -f $(RELEASE_DIR)/*.exe
	rm -f $(RELEASE_OBJS_DIR)/*.o

cleand:
	rm -f $(DEBUG_DIR)/*.exe
	rm -f $(DEBUG_OBJS_DIR)/*.o

# Todo only once to make folders
prep:
	mkdir $(DEBUG_DIR) | mkdir $(RELEASE_DIR)
	mkdir $(DEBUG_DIR)/OBJ | mkdir $(RELEASE_DIR)/OBJ

.PHONY: exe clean