# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Users/pisan/homebrew/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /Users/pisan/homebrew/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pisan/bitbucket/pisan343/ass2-bst

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pisan/bitbucket/pisan343/ass2-bst

# Include any dependencies generated for this target.
include CMakeFiles/ass2-bst.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ass2-bst.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ass2-bst.dir/flags.make

CMakeFiles/ass2-bst.dir/main.cpp.o: CMakeFiles/ass2-bst.dir/flags.make
CMakeFiles/ass2-bst.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pisan/bitbucket/pisan343/ass2-bst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ass2-bst.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ass2-bst.dir/main.cpp.o -c /Users/pisan/bitbucket/pisan343/ass2-bst/main.cpp

CMakeFiles/ass2-bst.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass2-bst.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pisan/bitbucket/pisan343/ass2-bst/main.cpp > CMakeFiles/ass2-bst.dir/main.cpp.i

CMakeFiles/ass2-bst.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass2-bst.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pisan/bitbucket/pisan343/ass2-bst/main.cpp -o CMakeFiles/ass2-bst.dir/main.cpp.s

CMakeFiles/ass2-bst.dir/bsttest.cpp.o: CMakeFiles/ass2-bst.dir/flags.make
CMakeFiles/ass2-bst.dir/bsttest.cpp.o: bsttest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pisan/bitbucket/pisan343/ass2-bst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ass2-bst.dir/bsttest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ass2-bst.dir/bsttest.cpp.o -c /Users/pisan/bitbucket/pisan343/ass2-bst/bsttest.cpp

CMakeFiles/ass2-bst.dir/bsttest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass2-bst.dir/bsttest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pisan/bitbucket/pisan343/ass2-bst/bsttest.cpp > CMakeFiles/ass2-bst.dir/bsttest.cpp.i

CMakeFiles/ass2-bst.dir/bsttest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass2-bst.dir/bsttest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pisan/bitbucket/pisan343/ass2-bst/bsttest.cpp -o CMakeFiles/ass2-bst.dir/bsttest.cpp.s

# Object files for target ass2-bst
ass2__bst_OBJECTS = \
"CMakeFiles/ass2-bst.dir/main.cpp.o" \
"CMakeFiles/ass2-bst.dir/bsttest.cpp.o"

# External object files for target ass2-bst
ass2__bst_EXTERNAL_OBJECTS =

ass2-bst: CMakeFiles/ass2-bst.dir/main.cpp.o
ass2-bst: CMakeFiles/ass2-bst.dir/bsttest.cpp.o
ass2-bst: CMakeFiles/ass2-bst.dir/build.make
ass2-bst: CMakeFiles/ass2-bst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pisan/bitbucket/pisan343/ass2-bst/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ass2-bst"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ass2-bst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ass2-bst.dir/build: ass2-bst

.PHONY : CMakeFiles/ass2-bst.dir/build

CMakeFiles/ass2-bst.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ass2-bst.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ass2-bst.dir/clean

CMakeFiles/ass2-bst.dir/depend:
	cd /Users/pisan/bitbucket/pisan343/ass2-bst && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pisan/bitbucket/pisan343/ass2-bst /Users/pisan/bitbucket/pisan343/ass2-bst /Users/pisan/bitbucket/pisan343/ass2-bst /Users/pisan/bitbucket/pisan343/ass2-bst /Users/pisan/bitbucket/pisan343/ass2-bst/CMakeFiles/ass2-bst.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ass2-bst.dir/depend

