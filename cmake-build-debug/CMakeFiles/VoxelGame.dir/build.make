# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /home/s/Downloads/clion-2020.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/s/Downloads/clion-2020.1.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/s/CLionProjects/VoxelGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/s/CLionProjects/VoxelGame/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/VoxelGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VoxelGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VoxelGame.dir/flags.make

CMakeFiles/VoxelGame.dir/main.cpp.o: CMakeFiles/VoxelGame.dir/flags.make
CMakeFiles/VoxelGame.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/CLionProjects/VoxelGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VoxelGame.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VoxelGame.dir/main.cpp.o -c /home/s/CLionProjects/VoxelGame/main.cpp

CMakeFiles/VoxelGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VoxelGame.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/CLionProjects/VoxelGame/main.cpp > CMakeFiles/VoxelGame.dir/main.cpp.i

CMakeFiles/VoxelGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VoxelGame.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/CLionProjects/VoxelGame/main.cpp -o CMakeFiles/VoxelGame.dir/main.cpp.s

CMakeFiles/VoxelGame.dir/graphics/window.cpp.o: CMakeFiles/VoxelGame.dir/flags.make
CMakeFiles/VoxelGame.dir/graphics/window.cpp.o: ../graphics/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/CLionProjects/VoxelGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VoxelGame.dir/graphics/window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VoxelGame.dir/graphics/window.cpp.o -c /home/s/CLionProjects/VoxelGame/graphics/window.cpp

CMakeFiles/VoxelGame.dir/graphics/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VoxelGame.dir/graphics/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/CLionProjects/VoxelGame/graphics/window.cpp > CMakeFiles/VoxelGame.dir/graphics/window.cpp.i

CMakeFiles/VoxelGame.dir/graphics/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VoxelGame.dir/graphics/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/CLionProjects/VoxelGame/graphics/window.cpp -o CMakeFiles/VoxelGame.dir/graphics/window.cpp.s

CMakeFiles/VoxelGame.dir/glad/src/glad.c.o: CMakeFiles/VoxelGame.dir/flags.make
CMakeFiles/VoxelGame.dir/glad/src/glad.c.o: ../glad/src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/CLionProjects/VoxelGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/VoxelGame.dir/glad/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/VoxelGame.dir/glad/src/glad.c.o   -c /home/s/CLionProjects/VoxelGame/glad/src/glad.c

CMakeFiles/VoxelGame.dir/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VoxelGame.dir/glad/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/s/CLionProjects/VoxelGame/glad/src/glad.c > CMakeFiles/VoxelGame.dir/glad/src/glad.c.i

CMakeFiles/VoxelGame.dir/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VoxelGame.dir/glad/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/s/CLionProjects/VoxelGame/glad/src/glad.c -o CMakeFiles/VoxelGame.dir/glad/src/glad.c.s

CMakeFiles/VoxelGame.dir/graphics/Model.cpp.o: CMakeFiles/VoxelGame.dir/flags.make
CMakeFiles/VoxelGame.dir/graphics/Model.cpp.o: ../graphics/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/CLionProjects/VoxelGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/VoxelGame.dir/graphics/Model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VoxelGame.dir/graphics/Model.cpp.o -c /home/s/CLionProjects/VoxelGame/graphics/Model.cpp

CMakeFiles/VoxelGame.dir/graphics/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VoxelGame.dir/graphics/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/CLionProjects/VoxelGame/graphics/Model.cpp > CMakeFiles/VoxelGame.dir/graphics/Model.cpp.i

CMakeFiles/VoxelGame.dir/graphics/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VoxelGame.dir/graphics/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/CLionProjects/VoxelGame/graphics/Model.cpp -o CMakeFiles/VoxelGame.dir/graphics/Model.cpp.s

CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.o: CMakeFiles/VoxelGame.dir/flags.make
CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.o: ../graphics/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/CLionProjects/VoxelGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.o -c /home/s/CLionProjects/VoxelGame/graphics/Shader.cpp

CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/CLionProjects/VoxelGame/graphics/Shader.cpp > CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.i

CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/CLionProjects/VoxelGame/graphics/Shader.cpp -o CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.s

CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.o: CMakeFiles/VoxelGame.dir/flags.make
CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.o: ../graphics/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/CLionProjects/VoxelGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.o -c /home/s/CLionProjects/VoxelGame/graphics/Camera.cpp

CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/CLionProjects/VoxelGame/graphics/Camera.cpp > CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.i

CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/CLionProjects/VoxelGame/graphics/Camera.cpp -o CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.s

CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.o: CMakeFiles/VoxelGame.dir/flags.make
CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.o: ../graphics/PerspectiveCamera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/CLionProjects/VoxelGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.o -c /home/s/CLionProjects/VoxelGame/graphics/PerspectiveCamera.cpp

CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/CLionProjects/VoxelGame/graphics/PerspectiveCamera.cpp > CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.i

CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/CLionProjects/VoxelGame/graphics/PerspectiveCamera.cpp -o CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.s

CMakeFiles/VoxelGame.dir/Chunk.cpp.o: CMakeFiles/VoxelGame.dir/flags.make
CMakeFiles/VoxelGame.dir/Chunk.cpp.o: ../Chunk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s/CLionProjects/VoxelGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/VoxelGame.dir/Chunk.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VoxelGame.dir/Chunk.cpp.o -c /home/s/CLionProjects/VoxelGame/Chunk.cpp

CMakeFiles/VoxelGame.dir/Chunk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VoxelGame.dir/Chunk.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s/CLionProjects/VoxelGame/Chunk.cpp > CMakeFiles/VoxelGame.dir/Chunk.cpp.i

CMakeFiles/VoxelGame.dir/Chunk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VoxelGame.dir/Chunk.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s/CLionProjects/VoxelGame/Chunk.cpp -o CMakeFiles/VoxelGame.dir/Chunk.cpp.s

# Object files for target VoxelGame
VoxelGame_OBJECTS = \
"CMakeFiles/VoxelGame.dir/main.cpp.o" \
"CMakeFiles/VoxelGame.dir/graphics/window.cpp.o" \
"CMakeFiles/VoxelGame.dir/glad/src/glad.c.o" \
"CMakeFiles/VoxelGame.dir/graphics/Model.cpp.o" \
"CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.o" \
"CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.o" \
"CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.o" \
"CMakeFiles/VoxelGame.dir/Chunk.cpp.o"

# External object files for target VoxelGame
VoxelGame_EXTERNAL_OBJECTS =

VoxelGame: CMakeFiles/VoxelGame.dir/main.cpp.o
VoxelGame: CMakeFiles/VoxelGame.dir/graphics/window.cpp.o
VoxelGame: CMakeFiles/VoxelGame.dir/glad/src/glad.c.o
VoxelGame: CMakeFiles/VoxelGame.dir/graphics/Model.cpp.o
VoxelGame: CMakeFiles/VoxelGame.dir/graphics/Shader.cpp.o
VoxelGame: CMakeFiles/VoxelGame.dir/graphics/Camera.cpp.o
VoxelGame: CMakeFiles/VoxelGame.dir/graphics/PerspectiveCamera.cpp.o
VoxelGame: CMakeFiles/VoxelGame.dir/Chunk.cpp.o
VoxelGame: CMakeFiles/VoxelGame.dir/build.make
VoxelGame: CMakeFiles/VoxelGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/s/CLionProjects/VoxelGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable VoxelGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VoxelGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VoxelGame.dir/build: VoxelGame

.PHONY : CMakeFiles/VoxelGame.dir/build

CMakeFiles/VoxelGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VoxelGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VoxelGame.dir/clean

CMakeFiles/VoxelGame.dir/depend:
	cd /home/s/CLionProjects/VoxelGame/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/s/CLionProjects/VoxelGame /home/s/CLionProjects/VoxelGame /home/s/CLionProjects/VoxelGame/cmake-build-debug /home/s/CLionProjects/VoxelGame/cmake-build-debug /home/s/CLionProjects/VoxelGame/cmake-build-debug/CMakeFiles/VoxelGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VoxelGame.dir/depend

