# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lenovo/Computer-Networks-2020Fall

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lenovo/Computer-Networks-2020Fall/build

# Include any dependencies generated for this target.
include CMakeFiles/ctest_eth_in.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ctest_eth_in.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ctest_eth_in.dir/flags.make

CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o: CMakeFiles/ctest_eth_in.dir/flags.make
CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o: ../test/eth_in_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lenovo/Computer-Networks-2020Fall/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o   -c /home/lenovo/Computer-Networks-2020Fall/test/eth_in_test.c

CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.i"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lenovo/Computer-Networks-2020Fall/test/eth_in_test.c > CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.i

CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.s"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lenovo/Computer-Networks-2020Fall/test/eth_in_test.c -o CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.s

CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o.requires:

.PHONY : CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o.requires

CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o.provides: CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o.requires
	$(MAKE) -f CMakeFiles/ctest_eth_in.dir/build.make CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o.provides.build
.PHONY : CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o.provides

CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o.provides.build: CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o


CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o: CMakeFiles/ctest_eth_in.dir/flags.make
CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o: ../src/ethernet.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lenovo/Computer-Networks-2020Fall/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o   -c /home/lenovo/Computer-Networks-2020Fall/src/ethernet.c

CMakeFiles/ctest_eth_in.dir/src/ethernet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ctest_eth_in.dir/src/ethernet.c.i"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lenovo/Computer-Networks-2020Fall/src/ethernet.c > CMakeFiles/ctest_eth_in.dir/src/ethernet.c.i

CMakeFiles/ctest_eth_in.dir/src/ethernet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ctest_eth_in.dir/src/ethernet.c.s"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lenovo/Computer-Networks-2020Fall/src/ethernet.c -o CMakeFiles/ctest_eth_in.dir/src/ethernet.c.s

CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o.requires:

.PHONY : CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o.requires

CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o.provides: CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o.requires
	$(MAKE) -f CMakeFiles/ctest_eth_in.dir/build.make CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o.provides.build
.PHONY : CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o.provides

CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o.provides.build: CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o


CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o: CMakeFiles/ctest_eth_in.dir/flags.make
CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o: ../test/faker/arp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lenovo/Computer-Networks-2020Fall/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o   -c /home/lenovo/Computer-Networks-2020Fall/test/faker/arp.c

CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.i"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lenovo/Computer-Networks-2020Fall/test/faker/arp.c > CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.i

CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.s"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lenovo/Computer-Networks-2020Fall/test/faker/arp.c -o CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.s

CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o.requires:

.PHONY : CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o.requires

CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o.provides: CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o.requires
	$(MAKE) -f CMakeFiles/ctest_eth_in.dir/build.make CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o.provides.build
.PHONY : CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o.provides

CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o.provides.build: CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o


CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o: CMakeFiles/ctest_eth_in.dir/flags.make
CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o: ../test/faker/ip.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lenovo/Computer-Networks-2020Fall/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o   -c /home/lenovo/Computer-Networks-2020Fall/test/faker/ip.c

CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.i"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lenovo/Computer-Networks-2020Fall/test/faker/ip.c > CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.i

CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.s"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lenovo/Computer-Networks-2020Fall/test/faker/ip.c -o CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.s

CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o.requires:

.PHONY : CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o.requires

CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o.provides: CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o.requires
	$(MAKE) -f CMakeFiles/ctest_eth_in.dir/build.make CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o.provides.build
.PHONY : CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o.provides

CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o.provides.build: CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o


CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o: CMakeFiles/ctest_eth_in.dir/flags.make
CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o: ../test/faker/driver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lenovo/Computer-Networks-2020Fall/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o   -c /home/lenovo/Computer-Networks-2020Fall/test/faker/driver.c

CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.i"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lenovo/Computer-Networks-2020Fall/test/faker/driver.c > CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.i

CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.s"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lenovo/Computer-Networks-2020Fall/test/faker/driver.c -o CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.s

CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o.requires:

.PHONY : CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o.requires

CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o.provides: CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o.requires
	$(MAKE) -f CMakeFiles/ctest_eth_in.dir/build.make CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o.provides.build
.PHONY : CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o.provides

CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o.provides.build: CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o


CMakeFiles/ctest_eth_in.dir/test/global.c.o: CMakeFiles/ctest_eth_in.dir/flags.make
CMakeFiles/ctest_eth_in.dir/test/global.c.o: ../test/global.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lenovo/Computer-Networks-2020Fall/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ctest_eth_in.dir/test/global.c.o"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ctest_eth_in.dir/test/global.c.o   -c /home/lenovo/Computer-Networks-2020Fall/test/global.c

CMakeFiles/ctest_eth_in.dir/test/global.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ctest_eth_in.dir/test/global.c.i"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lenovo/Computer-Networks-2020Fall/test/global.c > CMakeFiles/ctest_eth_in.dir/test/global.c.i

CMakeFiles/ctest_eth_in.dir/test/global.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ctest_eth_in.dir/test/global.c.s"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lenovo/Computer-Networks-2020Fall/test/global.c -o CMakeFiles/ctest_eth_in.dir/test/global.c.s

CMakeFiles/ctest_eth_in.dir/test/global.c.o.requires:

.PHONY : CMakeFiles/ctest_eth_in.dir/test/global.c.o.requires

CMakeFiles/ctest_eth_in.dir/test/global.c.o.provides: CMakeFiles/ctest_eth_in.dir/test/global.c.o.requires
	$(MAKE) -f CMakeFiles/ctest_eth_in.dir/build.make CMakeFiles/ctest_eth_in.dir/test/global.c.o.provides.build
.PHONY : CMakeFiles/ctest_eth_in.dir/test/global.c.o.provides

CMakeFiles/ctest_eth_in.dir/test/global.c.o.provides.build: CMakeFiles/ctest_eth_in.dir/test/global.c.o


CMakeFiles/ctest_eth_in.dir/src/utils.c.o: CMakeFiles/ctest_eth_in.dir/flags.make
CMakeFiles/ctest_eth_in.dir/src/utils.c.o: ../src/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lenovo/Computer-Networks-2020Fall/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/ctest_eth_in.dir/src/utils.c.o"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ctest_eth_in.dir/src/utils.c.o   -c /home/lenovo/Computer-Networks-2020Fall/src/utils.c

CMakeFiles/ctest_eth_in.dir/src/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ctest_eth_in.dir/src/utils.c.i"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lenovo/Computer-Networks-2020Fall/src/utils.c > CMakeFiles/ctest_eth_in.dir/src/utils.c.i

CMakeFiles/ctest_eth_in.dir/src/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ctest_eth_in.dir/src/utils.c.s"
	/usr/bin/gcc-5  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lenovo/Computer-Networks-2020Fall/src/utils.c -o CMakeFiles/ctest_eth_in.dir/src/utils.c.s

CMakeFiles/ctest_eth_in.dir/src/utils.c.o.requires:

.PHONY : CMakeFiles/ctest_eth_in.dir/src/utils.c.o.requires

CMakeFiles/ctest_eth_in.dir/src/utils.c.o.provides: CMakeFiles/ctest_eth_in.dir/src/utils.c.o.requires
	$(MAKE) -f CMakeFiles/ctest_eth_in.dir/build.make CMakeFiles/ctest_eth_in.dir/src/utils.c.o.provides.build
.PHONY : CMakeFiles/ctest_eth_in.dir/src/utils.c.o.provides

CMakeFiles/ctest_eth_in.dir/src/utils.c.o.provides.build: CMakeFiles/ctest_eth_in.dir/src/utils.c.o


# Object files for target ctest_eth_in
ctest_eth_in_OBJECTS = \
"CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o" \
"CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o" \
"CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o" \
"CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o" \
"CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o" \
"CMakeFiles/ctest_eth_in.dir/test/global.c.o" \
"CMakeFiles/ctest_eth_in.dir/src/utils.c.o"

# External object files for target ctest_eth_in
ctest_eth_in_EXTERNAL_OBJECTS =

../test/ctest_eth_in: CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o
../test/ctest_eth_in: CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o
../test/ctest_eth_in: CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o
../test/ctest_eth_in: CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o
../test/ctest_eth_in: CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o
../test/ctest_eth_in: CMakeFiles/ctest_eth_in.dir/test/global.c.o
../test/ctest_eth_in: CMakeFiles/ctest_eth_in.dir/src/utils.c.o
../test/ctest_eth_in: CMakeFiles/ctest_eth_in.dir/build.make
../test/ctest_eth_in: CMakeFiles/ctest_eth_in.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lenovo/Computer-Networks-2020Fall/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable ../test/ctest_eth_in"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ctest_eth_in.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ctest_eth_in.dir/build: ../test/ctest_eth_in

.PHONY : CMakeFiles/ctest_eth_in.dir/build

CMakeFiles/ctest_eth_in.dir/requires: CMakeFiles/ctest_eth_in.dir/test/eth_in_test.c.o.requires
CMakeFiles/ctest_eth_in.dir/requires: CMakeFiles/ctest_eth_in.dir/src/ethernet.c.o.requires
CMakeFiles/ctest_eth_in.dir/requires: CMakeFiles/ctest_eth_in.dir/test/faker/arp.c.o.requires
CMakeFiles/ctest_eth_in.dir/requires: CMakeFiles/ctest_eth_in.dir/test/faker/ip.c.o.requires
CMakeFiles/ctest_eth_in.dir/requires: CMakeFiles/ctest_eth_in.dir/test/faker/driver.c.o.requires
CMakeFiles/ctest_eth_in.dir/requires: CMakeFiles/ctest_eth_in.dir/test/global.c.o.requires
CMakeFiles/ctest_eth_in.dir/requires: CMakeFiles/ctest_eth_in.dir/src/utils.c.o.requires

.PHONY : CMakeFiles/ctest_eth_in.dir/requires

CMakeFiles/ctest_eth_in.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ctest_eth_in.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ctest_eth_in.dir/clean

CMakeFiles/ctest_eth_in.dir/depend:
	cd /home/lenovo/Computer-Networks-2020Fall/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lenovo/Computer-Networks-2020Fall /home/lenovo/Computer-Networks-2020Fall /home/lenovo/Computer-Networks-2020Fall/build /home/lenovo/Computer-Networks-2020Fall/build /home/lenovo/Computer-Networks-2020Fall/build/CMakeFiles/ctest_eth_in.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ctest_eth_in.dir/depend

