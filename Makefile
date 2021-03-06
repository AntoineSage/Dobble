# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target package
package: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool..."
	/usr/bin/cpack --config ./CPackConfig.cmake
.PHONY : package

# Special rule for the target package
package/fast: package

.PHONY : package/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target package_source
package_source:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Run CPack packaging tool for source..."
	/usr/bin/cpack --config ./CPackSourceConfig.cmake /home/antoine/INFO3S1/API/dobble/CPackSourceConfig.cmake
.PHONY : package_source

# Special rule for the target package_source
package_source/fast: package_source

.PHONY : package_source/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/antoine/INFO3S1/API/dobble/CMakeFiles /home/antoine/INFO3S1/API/dobble/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/antoine/INFO3S1/API/dobble/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named testCarteAleat

# Build rule for target.
testCarteAleat: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 testCarteAleat
.PHONY : testCarteAleat

# fast build rule for target.
testCarteAleat/fast:
	$(MAKE) -f CMakeFiles/testCarteAleat.dir/build.make CMakeFiles/testCarteAleat.dir/build
.PHONY : testCarteAleat/fast

#=============================================================================
# Target rules for targets named testClic

# Build rule for target.
testClic: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 testClic
.PHONY : testClic

# fast build rule for target.
testClic/fast:
	$(MAKE) -f CMakeFiles/testClic.dir/build.make CMakeFiles/testClic.dir/build
.PHONY : testClic/fast

#=============================================================================
# Target rules for targets named testRandomCard

# Build rule for target.
testRandomCard: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 testRandomCard
.PHONY : testRandomCard

# fast build rule for target.
testRandomCard/fast:
	$(MAKE) -f CMakeFiles/testRandomCard.dir/build.make CMakeFiles/testRandomCard.dir/build
.PHONY : testRandomCard/fast

#=============================================================================
# Target rules for targets named dobble

# Build rule for target.
dobble: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 dobble
.PHONY : dobble

# fast build rule for target.
dobble/fast:
	$(MAKE) -f CMakeFiles/dobble.dir/build.make CMakeFiles/dobble.dir/build
.PHONY : dobble/fast

#=============================================================================
# Target rules for targets named dobble_core

# Build rule for target.
dobble_core: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 dobble_core
.PHONY : dobble_core

# fast build rule for target.
dobble_core/fast:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/build
.PHONY : dobble_core/fast

#=============================================================================
# Target rules for targets named testRandomLocation

# Build rule for target.
testRandomLocation: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 testRandomLocation
.PHONY : testRandomLocation

# fast build rule for target.
testRandomLocation/fast:
	$(MAKE) -f CMakeFiles/testRandomLocation.dir/build.make CMakeFiles/testRandomLocation.dir/build
.PHONY : testRandomLocation/fast

#=============================================================================
# Target rules for targets named testFichierVersPlateau

# Build rule for target.
testFichierVersPlateau: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 testFichierVersPlateau
.PHONY : testFichierVersPlateau

# fast build rule for target.
testFichierVersPlateau/fast:
	$(MAKE) -f CMakeFiles/testFichierVersPlateau.dir/build.make CMakeFiles/testFichierVersPlateau.dir/build
.PHONY : testFichierVersPlateau/fast

#=============================================================================
# Target rules for targets named testRandomLocationGraphic

# Build rule for target.
testRandomLocationGraphic: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 testRandomLocationGraphic
.PHONY : testRandomLocationGraphic

# fast build rule for target.
testRandomLocationGraphic/fast:
	$(MAKE) -f CMakeFiles/testRandomLocationGraphic.dir/build.make CMakeFiles/testRandomLocationGraphic.dir/build
.PHONY : testRandomLocationGraphic/fast

#=============================================================================
# Target rules for targets named testMain

# Build rule for target.
testMain: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 testMain
.PHONY : testMain

# fast build rule for target.
testMain/fast:
	$(MAKE) -f CMakeFiles/testMain.dir/build.make CMakeFiles/testMain.dir/build
.PHONY : testMain/fast

src/Vect2.o: src/Vect2.c.o

.PHONY : src/Vect2.o

# target to build an object file
src/Vect2.c.o:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/Vect2.c.o
.PHONY : src/Vect2.c.o

src/Vect2.i: src/Vect2.c.i

.PHONY : src/Vect2.i

# target to preprocess a source file
src/Vect2.c.i:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/Vect2.c.i
.PHONY : src/Vect2.c.i

src/Vect2.s: src/Vect2.c.s

.PHONY : src/Vect2.s

# target to generate assembly for a file
src/Vect2.c.s:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/Vect2.c.s
.PHONY : src/Vect2.c.s

src/carte.o: src/carte.c.o

.PHONY : src/carte.o

# target to build an object file
src/carte.c.o:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/carte.c.o
.PHONY : src/carte.c.o

src/carte.i: src/carte.c.i

.PHONY : src/carte.i

# target to preprocess a source file
src/carte.c.i:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/carte.c.i
.PHONY : src/carte.c.i

src/carte.s: src/carte.c.s

.PHONY : src/carte.s

# target to generate assembly for a file
src/carte.c.s:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/carte.c.s
.PHONY : src/carte.c.s

src/dobble.o: src/dobble.c.o

.PHONY : src/dobble.o

# target to build an object file
src/dobble.c.o:
	$(MAKE) -f CMakeFiles/dobble.dir/build.make CMakeFiles/dobble.dir/src/dobble.c.o
.PHONY : src/dobble.c.o

src/dobble.i: src/dobble.c.i

.PHONY : src/dobble.i

# target to preprocess a source file
src/dobble.c.i:
	$(MAKE) -f CMakeFiles/dobble.dir/build.make CMakeFiles/dobble.dir/src/dobble.c.i
.PHONY : src/dobble.c.i

src/dobble.s: src/dobble.c.s

.PHONY : src/dobble.s

# target to generate assembly for a file
src/dobble.c.s:
	$(MAKE) -f CMakeFiles/dobble.dir/build.make CMakeFiles/dobble.dir/src/dobble.c.s
.PHONY : src/dobble.c.s

src/fichierVersPlateau.o: src/fichierVersPlateau.c.o

.PHONY : src/fichierVersPlateau.o

# target to build an object file
src/fichierVersPlateau.c.o:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/fichierVersPlateau.c.o
.PHONY : src/fichierVersPlateau.c.o

src/fichierVersPlateau.i: src/fichierVersPlateau.c.i

.PHONY : src/fichierVersPlateau.i

# target to preprocess a source file
src/fichierVersPlateau.c.i:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/fichierVersPlateau.c.i
.PHONY : src/fichierVersPlateau.c.i

src/fichierVersPlateau.s: src/fichierVersPlateau.c.s

.PHONY : src/fichierVersPlateau.s

# target to generate assembly for a file
src/fichierVersPlateau.c.s:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/fichierVersPlateau.c.s
.PHONY : src/fichierVersPlateau.c.s

src/graphics.o: src/graphics.c.o

.PHONY : src/graphics.o

# target to build an object file
src/graphics.c.o:
	$(MAKE) -f CMakeFiles/testRandomCard.dir/build.make CMakeFiles/testRandomCard.dir/src/graphics.c.o
	$(MAKE) -f CMakeFiles/dobble.dir/build.make CMakeFiles/dobble.dir/src/graphics.c.o
	$(MAKE) -f CMakeFiles/testRandomLocationGraphic.dir/build.make CMakeFiles/testRandomLocationGraphic.dir/src/graphics.c.o
	$(MAKE) -f CMakeFiles/testMain.dir/build.make CMakeFiles/testMain.dir/src/graphics.c.o
.PHONY : src/graphics.c.o

src/graphics.i: src/graphics.c.i

.PHONY : src/graphics.i

# target to preprocess a source file
src/graphics.c.i:
	$(MAKE) -f CMakeFiles/testRandomCard.dir/build.make CMakeFiles/testRandomCard.dir/src/graphics.c.i
	$(MAKE) -f CMakeFiles/dobble.dir/build.make CMakeFiles/dobble.dir/src/graphics.c.i
	$(MAKE) -f CMakeFiles/testRandomLocationGraphic.dir/build.make CMakeFiles/testRandomLocationGraphic.dir/src/graphics.c.i
	$(MAKE) -f CMakeFiles/testMain.dir/build.make CMakeFiles/testMain.dir/src/graphics.c.i
.PHONY : src/graphics.c.i

src/graphics.s: src/graphics.c.s

.PHONY : src/graphics.s

# target to generate assembly for a file
src/graphics.c.s:
	$(MAKE) -f CMakeFiles/testRandomCard.dir/build.make CMakeFiles/testRandomCard.dir/src/graphics.c.s
	$(MAKE) -f CMakeFiles/dobble.dir/build.make CMakeFiles/dobble.dir/src/graphics.c.s
	$(MAKE) -f CMakeFiles/testRandomLocationGraphic.dir/build.make CMakeFiles/testRandomLocationGraphic.dir/src/graphics.c.s
	$(MAKE) -f CMakeFiles/testMain.dir/build.make CMakeFiles/testMain.dir/src/graphics.c.s
.PHONY : src/graphics.c.s

src/icone.o: src/icone.c.o

.PHONY : src/icone.o

# target to build an object file
src/icone.c.o:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/icone.c.o
.PHONY : src/icone.c.o

src/icone.i: src/icone.c.i

.PHONY : src/icone.i

# target to preprocess a source file
src/icone.c.i:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/icone.c.i
.PHONY : src/icone.c.i

src/icone.s: src/icone.c.s

.PHONY : src/icone.s

# target to generate assembly for a file
src/icone.c.s:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/icone.c.s
.PHONY : src/icone.c.s

src/plateau.o: src/plateau.c.o

.PHONY : src/plateau.o

# target to build an object file
src/plateau.c.o:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/plateau.c.o
.PHONY : src/plateau.c.o

src/plateau.i: src/plateau.c.i

.PHONY : src/plateau.i

# target to preprocess a source file
src/plateau.c.i:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/plateau.c.i
.PHONY : src/plateau.c.i

src/plateau.s: src/plateau.c.s

.PHONY : src/plateau.s

# target to generate assembly for a file
src/plateau.c.s:
	$(MAKE) -f CMakeFiles/dobble_core.dir/build.make CMakeFiles/dobble_core.dir/src/plateau.c.s
.PHONY : src/plateau.c.s

tests/testCarteAleat.o: tests/testCarteAleat.c.o

.PHONY : tests/testCarteAleat.o

# target to build an object file
tests/testCarteAleat.c.o:
	$(MAKE) -f CMakeFiles/testCarteAleat.dir/build.make CMakeFiles/testCarteAleat.dir/tests/testCarteAleat.c.o
.PHONY : tests/testCarteAleat.c.o

tests/testCarteAleat.i: tests/testCarteAleat.c.i

.PHONY : tests/testCarteAleat.i

# target to preprocess a source file
tests/testCarteAleat.c.i:
	$(MAKE) -f CMakeFiles/testCarteAleat.dir/build.make CMakeFiles/testCarteAleat.dir/tests/testCarteAleat.c.i
.PHONY : tests/testCarteAleat.c.i

tests/testCarteAleat.s: tests/testCarteAleat.c.s

.PHONY : tests/testCarteAleat.s

# target to generate assembly for a file
tests/testCarteAleat.c.s:
	$(MAKE) -f CMakeFiles/testCarteAleat.dir/build.make CMakeFiles/testCarteAleat.dir/tests/testCarteAleat.c.s
.PHONY : tests/testCarteAleat.c.s

tests/testClic.o: tests/testClic.c.o

.PHONY : tests/testClic.o

# target to build an object file
tests/testClic.c.o:
	$(MAKE) -f CMakeFiles/testClic.dir/build.make CMakeFiles/testClic.dir/tests/testClic.c.o
.PHONY : tests/testClic.c.o

tests/testClic.i: tests/testClic.c.i

.PHONY : tests/testClic.i

# target to preprocess a source file
tests/testClic.c.i:
	$(MAKE) -f CMakeFiles/testClic.dir/build.make CMakeFiles/testClic.dir/tests/testClic.c.i
.PHONY : tests/testClic.c.i

tests/testClic.s: tests/testClic.c.s

.PHONY : tests/testClic.s

# target to generate assembly for a file
tests/testClic.c.s:
	$(MAKE) -f CMakeFiles/testClic.dir/build.make CMakeFiles/testClic.dir/tests/testClic.c.s
.PHONY : tests/testClic.c.s

tests/testFichierVersPlateau.o: tests/testFichierVersPlateau.c.o

.PHONY : tests/testFichierVersPlateau.o

# target to build an object file
tests/testFichierVersPlateau.c.o:
	$(MAKE) -f CMakeFiles/testFichierVersPlateau.dir/build.make CMakeFiles/testFichierVersPlateau.dir/tests/testFichierVersPlateau.c.o
.PHONY : tests/testFichierVersPlateau.c.o

tests/testFichierVersPlateau.i: tests/testFichierVersPlateau.c.i

.PHONY : tests/testFichierVersPlateau.i

# target to preprocess a source file
tests/testFichierVersPlateau.c.i:
	$(MAKE) -f CMakeFiles/testFichierVersPlateau.dir/build.make CMakeFiles/testFichierVersPlateau.dir/tests/testFichierVersPlateau.c.i
.PHONY : tests/testFichierVersPlateau.c.i

tests/testFichierVersPlateau.s: tests/testFichierVersPlateau.c.s

.PHONY : tests/testFichierVersPlateau.s

# target to generate assembly for a file
tests/testFichierVersPlateau.c.s:
	$(MAKE) -f CMakeFiles/testFichierVersPlateau.dir/build.make CMakeFiles/testFichierVersPlateau.dir/tests/testFichierVersPlateau.c.s
.PHONY : tests/testFichierVersPlateau.c.s

tests/testMain.o: tests/testMain.c.o

.PHONY : tests/testMain.o

# target to build an object file
tests/testMain.c.o:
	$(MAKE) -f CMakeFiles/testMain.dir/build.make CMakeFiles/testMain.dir/tests/testMain.c.o
.PHONY : tests/testMain.c.o

tests/testMain.i: tests/testMain.c.i

.PHONY : tests/testMain.i

# target to preprocess a source file
tests/testMain.c.i:
	$(MAKE) -f CMakeFiles/testMain.dir/build.make CMakeFiles/testMain.dir/tests/testMain.c.i
.PHONY : tests/testMain.c.i

tests/testMain.s: tests/testMain.c.s

.PHONY : tests/testMain.s

# target to generate assembly for a file
tests/testMain.c.s:
	$(MAKE) -f CMakeFiles/testMain.dir/build.make CMakeFiles/testMain.dir/tests/testMain.c.s
.PHONY : tests/testMain.c.s

tests/testRandomCard.o: tests/testRandomCard.c.o

.PHONY : tests/testRandomCard.o

# target to build an object file
tests/testRandomCard.c.o:
	$(MAKE) -f CMakeFiles/testRandomCard.dir/build.make CMakeFiles/testRandomCard.dir/tests/testRandomCard.c.o
.PHONY : tests/testRandomCard.c.o

tests/testRandomCard.i: tests/testRandomCard.c.i

.PHONY : tests/testRandomCard.i

# target to preprocess a source file
tests/testRandomCard.c.i:
	$(MAKE) -f CMakeFiles/testRandomCard.dir/build.make CMakeFiles/testRandomCard.dir/tests/testRandomCard.c.i
.PHONY : tests/testRandomCard.c.i

tests/testRandomCard.s: tests/testRandomCard.c.s

.PHONY : tests/testRandomCard.s

# target to generate assembly for a file
tests/testRandomCard.c.s:
	$(MAKE) -f CMakeFiles/testRandomCard.dir/build.make CMakeFiles/testRandomCard.dir/tests/testRandomCard.c.s
.PHONY : tests/testRandomCard.c.s

tests/testRandomLocation.o: tests/testRandomLocation.c.o

.PHONY : tests/testRandomLocation.o

# target to build an object file
tests/testRandomLocation.c.o:
	$(MAKE) -f CMakeFiles/testRandomLocation.dir/build.make CMakeFiles/testRandomLocation.dir/tests/testRandomLocation.c.o
.PHONY : tests/testRandomLocation.c.o

tests/testRandomLocation.i: tests/testRandomLocation.c.i

.PHONY : tests/testRandomLocation.i

# target to preprocess a source file
tests/testRandomLocation.c.i:
	$(MAKE) -f CMakeFiles/testRandomLocation.dir/build.make CMakeFiles/testRandomLocation.dir/tests/testRandomLocation.c.i
.PHONY : tests/testRandomLocation.c.i

tests/testRandomLocation.s: tests/testRandomLocation.c.s

.PHONY : tests/testRandomLocation.s

# target to generate assembly for a file
tests/testRandomLocation.c.s:
	$(MAKE) -f CMakeFiles/testRandomLocation.dir/build.make CMakeFiles/testRandomLocation.dir/tests/testRandomLocation.c.s
.PHONY : tests/testRandomLocation.c.s

tests/testRandomLocationGraphic.o: tests/testRandomLocationGraphic.c.o

.PHONY : tests/testRandomLocationGraphic.o

# target to build an object file
tests/testRandomLocationGraphic.c.o:
	$(MAKE) -f CMakeFiles/testRandomLocationGraphic.dir/build.make CMakeFiles/testRandomLocationGraphic.dir/tests/testRandomLocationGraphic.c.o
.PHONY : tests/testRandomLocationGraphic.c.o

tests/testRandomLocationGraphic.i: tests/testRandomLocationGraphic.c.i

.PHONY : tests/testRandomLocationGraphic.i

# target to preprocess a source file
tests/testRandomLocationGraphic.c.i:
	$(MAKE) -f CMakeFiles/testRandomLocationGraphic.dir/build.make CMakeFiles/testRandomLocationGraphic.dir/tests/testRandomLocationGraphic.c.i
.PHONY : tests/testRandomLocationGraphic.c.i

tests/testRandomLocationGraphic.s: tests/testRandomLocationGraphic.c.s

.PHONY : tests/testRandomLocationGraphic.s

# target to generate assembly for a file
tests/testRandomLocationGraphic.c.s:
	$(MAKE) -f CMakeFiles/testRandomLocationGraphic.dir/build.make CMakeFiles/testRandomLocationGraphic.dir/tests/testRandomLocationGraphic.c.s
.PHONY : tests/testRandomLocationGraphic.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... testCarteAleat"
	@echo "... testClic"
	@echo "... testRandomCard"
	@echo "... dobble"
	@echo "... package"
	@echo "... dobble_core"
	@echo "... edit_cache"
	@echo "... testRandomLocation"
	@echo "... package_source"
	@echo "... testFichierVersPlateau"
	@echo "... testRandomLocationGraphic"
	@echo "... testMain"
	@echo "... src/Vect2.o"
	@echo "... src/Vect2.i"
	@echo "... src/Vect2.s"
	@echo "... src/carte.o"
	@echo "... src/carte.i"
	@echo "... src/carte.s"
	@echo "... src/dobble.o"
	@echo "... src/dobble.i"
	@echo "... src/dobble.s"
	@echo "... src/fichierVersPlateau.o"
	@echo "... src/fichierVersPlateau.i"
	@echo "... src/fichierVersPlateau.s"
	@echo "... src/graphics.o"
	@echo "... src/graphics.i"
	@echo "... src/graphics.s"
	@echo "... src/icone.o"
	@echo "... src/icone.i"
	@echo "... src/icone.s"
	@echo "... src/plateau.o"
	@echo "... src/plateau.i"
	@echo "... src/plateau.s"
	@echo "... tests/testCarteAleat.o"
	@echo "... tests/testCarteAleat.i"
	@echo "... tests/testCarteAleat.s"
	@echo "... tests/testClic.o"
	@echo "... tests/testClic.i"
	@echo "... tests/testClic.s"
	@echo "... tests/testFichierVersPlateau.o"
	@echo "... tests/testFichierVersPlateau.i"
	@echo "... tests/testFichierVersPlateau.s"
	@echo "... tests/testMain.o"
	@echo "... tests/testMain.i"
	@echo "... tests/testMain.s"
	@echo "... tests/testRandomCard.o"
	@echo "... tests/testRandomCard.i"
	@echo "... tests/testRandomCard.s"
	@echo "... tests/testRandomLocation.o"
	@echo "... tests/testRandomLocation.i"
	@echo "... tests/testRandomLocation.s"
	@echo "... tests/testRandomLocationGraphic.o"
	@echo "... tests/testRandomLocationGraphic.i"
	@echo "... tests/testRandomLocationGraphic.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

