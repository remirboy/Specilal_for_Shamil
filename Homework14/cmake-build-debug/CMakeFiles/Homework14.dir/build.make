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
CMAKE_SOURCE_DIR = /Users/remir/CLionProjects/Homework14

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/remir/CLionProjects/Homework14/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Homework14.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Homework14.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Homework14.dir/flags.make

CMakeFiles/Homework14.dir/main.cpp.o: CMakeFiles/Homework14.dir/flags.make
CMakeFiles/Homework14.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/remir/CLionProjects/Homework14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Homework14.dir/main.cpp.o"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Homework14.dir/main.cpp.o -c /Users/remir/CLionProjects/Homework14/main.cpp

CMakeFiles/Homework14.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework14.dir/main.cpp.i"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/remir/CLionProjects/Homework14/main.cpp > CMakeFiles/Homework14.dir/main.cpp.i

CMakeFiles/Homework14.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework14.dir/main.cpp.s"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/remir/CLionProjects/Homework14/main.cpp -o CMakeFiles/Homework14.dir/main.cpp.s

# Object files for target Homework14
Homework14_OBJECTS = \
"CMakeFiles/Homework14.dir/main.cpp.o"

# External object files for target Homework14
Homework14_EXTERNAL_OBJECTS =

Homework14: CMakeFiles/Homework14.dir/main.cpp.o
Homework14: CMakeFiles/Homework14.dir/build.make
Homework14: CMakeFiles/Homework14.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/remir/CLionProjects/Homework14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Homework14"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Homework14.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Homework14.dir/build: Homework14

.PHONY : CMakeFiles/Homework14.dir/build

CMakeFiles/Homework14.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Homework14.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Homework14.dir/clean

CMakeFiles/Homework14.dir/depend:
	cd /Users/remir/CLionProjects/Homework14/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/remir/CLionProjects/Homework14 /Users/remir/CLionProjects/Homework14 /Users/remir/CLionProjects/Homework14/cmake-build-debug /Users/remir/CLionProjects/Homework14/cmake-build-debug /Users/remir/CLionProjects/Homework14/cmake-build-debug/CMakeFiles/Homework14.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Homework14.dir/depend
