# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\vic\Desktop\snoopy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\vic\Desktop\snoopy\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/exec.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/exec.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exec.dir/flags.make

CMakeFiles/exec.dir/main.c.obj: CMakeFiles/exec.dir/flags.make
CMakeFiles/exec.dir/main.c.obj: C:/Users/vic/Desktop/snoopy/main.c
CMakeFiles/exec.dir/main.c.obj: CMakeFiles/exec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vic\Desktop\snoopy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/exec.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/exec.dir/main.c.obj -MF CMakeFiles\exec.dir\main.c.obj.d -o CMakeFiles\exec.dir\main.c.obj -c C:\Users\vic\Desktop\snoopy\main.c

CMakeFiles/exec.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exec.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\vic\Desktop\snoopy\main.c > CMakeFiles\exec.dir\main.c.i

CMakeFiles/exec.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exec.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\vic\Desktop\snoopy\main.c -o CMakeFiles\exec.dir\main.c.s

# Object files for target exec
exec_OBJECTS = \
"CMakeFiles/exec.dir/main.c.obj"

# External object files for target exec
exec_EXTERNAL_OBJECTS =

exec.exe: CMakeFiles/exec.dir/main.c.obj
exec.exe: CMakeFiles/exec.dir/build.make
exec.exe: CMakeFiles/exec.dir/linkLibs.rsp
exec.exe: CMakeFiles/exec.dir/objects1.rsp
exec.exe: CMakeFiles/exec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\vic\Desktop\snoopy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable exec.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\exec.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exec.dir/build: exec.exe
.PHONY : CMakeFiles/exec.dir/build

CMakeFiles/exec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\exec.dir\cmake_clean.cmake
.PHONY : CMakeFiles/exec.dir/clean

CMakeFiles/exec.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\vic\Desktop\snoopy C:\Users\vic\Desktop\snoopy C:\Users\vic\Desktop\snoopy\cmake-build-debug C:\Users\vic\Desktop\snoopy\cmake-build-debug C:\Users\vic\Desktop\snoopy\cmake-build-debug\CMakeFiles\exec.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exec.dir/depend

