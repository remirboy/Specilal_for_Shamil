# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/remir/CLionProjects/MPI_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/remir/CLionProjects/MPI_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MPI_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MPI_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MPI_2.dir/flags.make

CMakeFiles/MPI_2.dir/main.cpp.o: CMakeFiles/MPI_2.dir/flags.make
CMakeFiles/MPI_2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/remir/CLionProjects/MPI_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MPI_2.dir/main.cpp.o"
	/usr/local/bin/mpicxx  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MPI_2.dir/main.cpp.o -c /Users/remir/CLionProjects/MPI_2/main.cpp

CMakeFiles/MPI_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MPI_2.dir/main.cpp.i"
	/usr/local/bin/mpicxx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/remir/CLionProjects/MPI_2/main.cpp > CMakeFiles/MPI_2.dir/main.cpp.i

CMakeFiles/MPI_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MPI_2.dir/main.cpp.s"
	/usr/local/bin/mpicxx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/remir/CLionProjects/MPI_2/main.cpp -o CMakeFiles/MPI_2.dir/main.cpp.s

# Object files for target MPI_2
MPI_2_OBJECTS = \
"CMakeFiles/MPI_2.dir/main.cpp.o"

# External object files for target MPI_2
MPI_2_EXTERNAL_OBJECTS =

MPI_2: CMakeFiles/MPI_2.dir/main.cpp.o
MPI_2: CMakeFiles/MPI_2.dir/build.make
MPI_2: CMakeFiles/MPI_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/remir/CLionProjects/MPI_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MPI_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MPI_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MPI_2.dir/build: MPI_2

.PHONY : CMakeFiles/MPI_2.dir/build

CMakeFiles/MPI_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MPI_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MPI_2.dir/clean

CMakeFiles/MPI_2.dir/depend:
	cd /Users/remir/CLionProjects/MPI_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/remir/CLionProjects/MPI_2 /Users/remir/CLionProjects/MPI_2 /Users/remir/CLionProjects/MPI_2/cmake-build-debug /Users/remir/CLionProjects/MPI_2/cmake-build-debug /Users/remir/CLionProjects/MPI_2/cmake-build-debug/CMakeFiles/MPI_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MPI_2.dir/depend

