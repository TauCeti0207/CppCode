# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files (x86)\cmake\cmake-3.22.2-windows-x86_64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\cmake\cmake-3.22.2-windows-x86_64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\code\2022code\Cpp_Code\2-22-Class&object"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\code\2022code\Cpp_Code\2-22-Class&object\build"

# Include any dependencies generated for this target.
include CMakeFiles/Date.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Date.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Date.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Date.dir/flags.make

CMakeFiles/Date.dir/src/Date.obj: CMakeFiles/Date.dir/flags.make
CMakeFiles/Date.dir/src/Date.obj: ../src/Date.cpp
CMakeFiles/Date.dir/src/Date.obj: CMakeFiles/Date.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\code\2022code\Cpp_Code\2-22-Class&object\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Date.dir/src/Date.obj"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Date.dir/src/Date.obj -MF CMakeFiles\Date.dir\src\Date.obj.d -o CMakeFiles\Date.dir\src\Date.obj -c "D:\code\2022code\Cpp_Code\2-22-Class&object\src\Date.cpp"

CMakeFiles/Date.dir/src/Date.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Date.dir/src/Date.i"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\code\2022code\Cpp_Code\2-22-Class&object\src\Date.cpp" > CMakeFiles\Date.dir\src\Date.i

CMakeFiles/Date.dir/src/Date.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Date.dir/src/Date.s"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\code\2022code\Cpp_Code\2-22-Class&object\src\Date.cpp" -o CMakeFiles\Date.dir\src\Date.s

CMakeFiles/Date.dir/src/test.obj: CMakeFiles/Date.dir/flags.make
CMakeFiles/Date.dir/src/test.obj: ../src/test.cpp
CMakeFiles/Date.dir/src/test.obj: CMakeFiles/Date.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\code\2022code\Cpp_Code\2-22-Class&object\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Date.dir/src/test.obj"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Date.dir/src/test.obj -MF CMakeFiles\Date.dir\src\test.obj.d -o CMakeFiles\Date.dir\src\test.obj -c "D:\code\2022code\Cpp_Code\2-22-Class&object\src\test.cpp"

CMakeFiles/Date.dir/src/test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Date.dir/src/test.i"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\code\2022code\Cpp_Code\2-22-Class&object\src\test.cpp" > CMakeFiles\Date.dir\src\test.i

CMakeFiles/Date.dir/src/test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Date.dir/src/test.s"
	D:\PROGRA~1\gcc\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\code\2022code\Cpp_Code\2-22-Class&object\src\test.cpp" -o CMakeFiles\Date.dir\src\test.s

# Object files for target Date
Date_OBJECTS = \
"CMakeFiles/Date.dir/src/Date.obj" \
"CMakeFiles/Date.dir/src/test.obj"

# External object files for target Date
Date_EXTERNAL_OBJECTS =

Date.exe: CMakeFiles/Date.dir/src/Date.obj
Date.exe: CMakeFiles/Date.dir/src/test.obj
Date.exe: CMakeFiles/Date.dir/build.make
Date.exe: CMakeFiles/Date.dir/linklibs.rsp
Date.exe: CMakeFiles/Date.dir/objects1.rsp
Date.exe: CMakeFiles/Date.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\code\2022code\Cpp_Code\2-22-Class&object\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Date.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Date.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Date.dir/build: Date.exe
.PHONY : CMakeFiles/Date.dir/build

CMakeFiles/Date.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Date.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Date.dir/clean

CMakeFiles/Date.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\code\2022code\Cpp_Code\2-22-Class&object" "D:\code\2022code\Cpp_Code\2-22-Class&object" "D:\code\2022code\Cpp_Code\2-22-Class&object\build" "D:\code\2022code\Cpp_Code\2-22-Class&object\build" "D:\code\2022code\Cpp_Code\2-22-Class&object\build\CMakeFiles\Date.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Date.dir/depend

