# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/antoine/INFO3S1/API/dobble

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/antoine/INFO3S1/API/dobble

# Include any dependencies generated for this target.
include CMakeFiles/testMain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testMain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testMain.dir/flags.make

CMakeFiles/testMain.dir/tests/testMain.c.o: CMakeFiles/testMain.dir/flags.make
CMakeFiles/testMain.dir/tests/testMain.c.o: tests/testMain.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antoine/INFO3S1/API/dobble/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/testMain.dir/tests/testMain.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testMain.dir/tests/testMain.c.o   -c /home/antoine/INFO3S1/API/dobble/tests/testMain.c

CMakeFiles/testMain.dir/tests/testMain.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testMain.dir/tests/testMain.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/antoine/INFO3S1/API/dobble/tests/testMain.c > CMakeFiles/testMain.dir/tests/testMain.c.i

CMakeFiles/testMain.dir/tests/testMain.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testMain.dir/tests/testMain.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/antoine/INFO3S1/API/dobble/tests/testMain.c -o CMakeFiles/testMain.dir/tests/testMain.c.s

CMakeFiles/testMain.dir/tests/testMain.c.o.requires:

.PHONY : CMakeFiles/testMain.dir/tests/testMain.c.o.requires

CMakeFiles/testMain.dir/tests/testMain.c.o.provides: CMakeFiles/testMain.dir/tests/testMain.c.o.requires
	$(MAKE) -f CMakeFiles/testMain.dir/build.make CMakeFiles/testMain.dir/tests/testMain.c.o.provides.build
.PHONY : CMakeFiles/testMain.dir/tests/testMain.c.o.provides

CMakeFiles/testMain.dir/tests/testMain.c.o.provides.build: CMakeFiles/testMain.dir/tests/testMain.c.o


CMakeFiles/testMain.dir/src/graphics.c.o: CMakeFiles/testMain.dir/flags.make
CMakeFiles/testMain.dir/src/graphics.c.o: src/graphics.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/antoine/INFO3S1/API/dobble/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/testMain.dir/src/graphics.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testMain.dir/src/graphics.c.o   -c /home/antoine/INFO3S1/API/dobble/src/graphics.c

CMakeFiles/testMain.dir/src/graphics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testMain.dir/src/graphics.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/antoine/INFO3S1/API/dobble/src/graphics.c > CMakeFiles/testMain.dir/src/graphics.c.i

CMakeFiles/testMain.dir/src/graphics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testMain.dir/src/graphics.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/antoine/INFO3S1/API/dobble/src/graphics.c -o CMakeFiles/testMain.dir/src/graphics.c.s

CMakeFiles/testMain.dir/src/graphics.c.o.requires:

.PHONY : CMakeFiles/testMain.dir/src/graphics.c.o.requires

CMakeFiles/testMain.dir/src/graphics.c.o.provides: CMakeFiles/testMain.dir/src/graphics.c.o.requires
	$(MAKE) -f CMakeFiles/testMain.dir/build.make CMakeFiles/testMain.dir/src/graphics.c.o.provides.build
.PHONY : CMakeFiles/testMain.dir/src/graphics.c.o.provides

CMakeFiles/testMain.dir/src/graphics.c.o.provides.build: CMakeFiles/testMain.dir/src/graphics.c.o


# Object files for target testMain
testMain_OBJECTS = \
"CMakeFiles/testMain.dir/tests/testMain.c.o" \
"CMakeFiles/testMain.dir/src/graphics.c.o"

# External object files for target testMain
testMain_EXTERNAL_OBJECTS = \
"/home/antoine/INFO3S1/API/dobble/CMakeFiles/dobble_core.dir/src/carte.c.o" \
"/home/antoine/INFO3S1/API/dobble/CMakeFiles/dobble_core.dir/src/fichierVersPlateau.c.o" \
"/home/antoine/INFO3S1/API/dobble/CMakeFiles/dobble_core.dir/src/icone.c.o" \
"/home/antoine/INFO3S1/API/dobble/CMakeFiles/dobble_core.dir/src/plateau.c.o" \
"/home/antoine/INFO3S1/API/dobble/CMakeFiles/dobble_core.dir/src/Vect2.c.o"

testMain: CMakeFiles/testMain.dir/tests/testMain.c.o
testMain: CMakeFiles/testMain.dir/src/graphics.c.o
testMain: CMakeFiles/dobble_core.dir/src/carte.c.o
testMain: CMakeFiles/dobble_core.dir/src/fichierVersPlateau.c.o
testMain: CMakeFiles/dobble_core.dir/src/icone.c.o
testMain: CMakeFiles/dobble_core.dir/src/plateau.c.o
testMain: CMakeFiles/dobble_core.dir/src/Vect2.c.o
testMain: CMakeFiles/testMain.dir/build.make
testMain: /usr/lib/x86_64-linux-gnu/libSDL2main.a
testMain: /usr/lib/x86_64-linux-gnu/libSDL2.so
testMain: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
testMain: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
testMain: CMakeFiles/testMain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/antoine/INFO3S1/API/dobble/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable testMain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testMain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testMain.dir/build: testMain

.PHONY : CMakeFiles/testMain.dir/build

CMakeFiles/testMain.dir/requires: CMakeFiles/testMain.dir/tests/testMain.c.o.requires
CMakeFiles/testMain.dir/requires: CMakeFiles/testMain.dir/src/graphics.c.o.requires

.PHONY : CMakeFiles/testMain.dir/requires

CMakeFiles/testMain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testMain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testMain.dir/clean

CMakeFiles/testMain.dir/depend:
	cd /home/antoine/INFO3S1/API/dobble && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/antoine/INFO3S1/API/dobble /home/antoine/INFO3S1/API/dobble /home/antoine/INFO3S1/API/dobble /home/antoine/INFO3S1/API/dobble /home/antoine/INFO3S1/API/dobble/CMakeFiles/testMain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testMain.dir/depend

