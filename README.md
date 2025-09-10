# clib2

This is Olaf Barthel's clib2, a standard C library for SAS/C and GCC compilers on Amiga.

## [amigazen project](http://www.amigazen.com)

*A web, suddenly*

*Forty years meditation*

*Minds awaken, free*

**amigazen project** uses modern software development tools and methods to update and rerelease classic Amiga open source software. Releases include a new AWeb, this new Amiga Python 2, and the ToolKit project - a universal SDK for Amiga.

Key to the amigazen project approach is ensuring every project can be built with the same common set of development tools and configurations, so the ToolKit project was created to provide a standard configuration for Amiga development. All *amigazen project* releases will be guaranteed to build against the ToolKit standard so that anyone can download and begin contributing straightaway without having to tailor the toolchain for their own setup.

The amigazen project philosophy is based on openness:

*Open* to anyone and everyone	- *Open* source and free for all	- *Open* your mind and create!

PRs for all of amigazen projects are gratefully received at [GitHub](https://github.com/amigazen/). While the focus now is on classic 68k software, it is intended that all amigazen project releases can be ported to other Amiga-like systems including AROS and MorphOS where feasible.

The original authors of the *clib2* software are not affiliated with the amigazen project. This software is redistributed on terms described in the documentation, particularly the file LICENSE.md

## About clib2

clib2 is a comprehensive standard C library implementation for Amiga, designed specifically for SAS/C and GCC compilers. This project aims to provide Amiga developers with a modern, standards-compliant C library that bridges the gap between classic Amiga development and contemporary POSIX, and thus code portability, standards.

Originally created by Olaf Barthel during two weeks in July 2002, clib2 was developed to enable porting Samba 2.2.x to the Amiga. When it became impossible to build Samba with SAS/C on the new Amiga platform, the development moved to the GNU 'C' compiler, which revealed the need for a more developed runtime library and header files.

Using 'C' - A Reference Manual (4th edition) as a reference, Olaf wrote a complete set of header files and implemented each function referenced in them. The result is a feature-complete implementation of the ISO 'C' (1994) runtime library, subsequently updated to offer functionality defined in ISO/IEC 9899:1999 (C99).

### Key Features

- **Complete C Library Replacement**: Offers a complete replacement c library and startup code for the SAS/C and GCC compilers, replacing sc.lib, scm.lib and c.o with c.lib, math.lib and startup.o for SAS/C and replacing libnix or ixemul for GCC
- **Enhanced Libraries**: Includes new versions of amiga.lib and debug.lib, usually provided in the Amiga NDK
- **POSIX Compatibility**: Complements standard C functionality with POSIX-like routines described in "Advanced programming in the Unix environment"
- **Amiga-Specific Design**: This is not a portable implementation - it's specifically designed for Amiga, taking advantage of routines available since Kickstart 2.04
- **Floating Point Support**: Supports floating point math for 68k platform (IEEE single and double precision or M68881 inline math) and PowerPC platform (double precision using fdlibm 5.3)
- **Thread Safety**: Optional thread-safe library variant when built with `__THREAD_SAFE` preprocessor symbol
- **Comprehensive Coverage**: With few exceptions in wide character support, provides a complete implementation of ISO 'C' (1994) and C99 standards

### Implementation Details

The library consists of 330+ source files, with each file containing one or two routines. File names are prefixed by the header file name where the corresponding routine is defined (e.g., `unistd_lchown.c` contains `lchown()` from `<unistd.h>`).

Internal functions and variables visible across modules are prefixed with two underscores (e.g., `__stdio_init()`). The library follows ISO 'C' conventions, with Amiga rules applied where implementation-defined behavior is permitted.

The source code was written virtually from scratch by Olaf Barthel, borrowing algorithmic ideas from BSD libc and the Manx Aztec 'C' runtime library. Code snippets for GCC environment expectations were borrowed from libnix by Matthias Fleischer and Gunther Nikl, particularly for integer and floating point math support, `setjmp`/`longjmp` routines, and startup code.

## About ToolKit

**ToolKit** exists to solve the problem that most Amiga software was written in the 1980s and 90s, by individuals working alone, each with their own preferred setup for where their dev tools are run from, where their include files, static libs and other toolchain artifacts could be found, which versions they used and which custom modifications they made. Open source collaboration did not exist as we know it in 2025. 

**ToolKit** from amigazen project is a work in progress to make a standardised installation of not just the Native Developer Kit, but the compilers, build tools and third party components needed to be able to consistently build projects in collaboration with others, without each contributor having to change build files to work with their particular toolchain configuration. 

All *amigazen project* releases will release in a ready to build configuration according to the ToolKit standard.

Each component of **ToolKit** is open source and will have it's own github repo, while ToolKit itself will eventually be released as an easy to install package containing the redistributable components, as well as scripts to easily install the parts that are not freely redistributable from archive.

## Changes in this ToolKit SDK version of clib2

The library code itself has not been changed, but some changes to the build system have been made to the build system. These changes are:

- Removed setup and cleanup targets from the SAS/C smakefile as these simply change the include paths to Olaf's local SDK configuration, which clashes with the ToolKit SDK include paths
- Added clib2's own include path to the smakefile so it doesn't try to include the SAS/C includes and clash with them
- Renamed the unix.lib target to x.lib to avoid clashes with unix.lib from UniLib3
- Set default CPU architecture to 68020 instead of 68030
- Changed names and locations of directories to match ToolKit standard project structure
- Included prebuilt binaries of the .lib files

Note that in this ToolKit SDK version the SAS/C smakefile produce the following target binaries:
- c.lib - the primary C library or 'libc'
- math.lib - the primary math library or 'libm'
- net.lib - sockets functions
- x.lib - Additional C library functions not included in c.lib. In the original version this target is called unix.lib but that name clashes with the already estbalished unix.lib by David Gay, now part of UniLib3, also from amigazen project
- amiga.lib - a replacement for the static amiga.lib provided with the NDK
- debug.lib - a replacement for the static debug.lib provided with the NDK
- startup.o - replacement startup code to use instead of c.o

## Building clib2

This slightly altered release of clib2 is designed to build against the ToolKit standard. The build process uses SAS/C with smake for Amiga, ensuring compatibility with classic Amiga development workflows.

Detailed build instructions are available in the [BUILD.md](BUILD.md) file.

### Prerequisites

- SAS/C compiler (primary target)
OR
- GCC compiler and adtools toolchain
- ToolKit development environment
- Amiga operating system 3.1 or higher

## Frequently Asked Questions

### Is clib2 a complete standalone C library?

Yes, clib2 is a complete standalone C library. It provides a feature-complete implementation of the ISO 'C' (1994) runtime library, updated to offer functionality defined in ISO/IEC 9899:1999 (C99). The library includes:

- Complete standard C library functions (stdio, stdlib, string, math, etc.)
- POSIX-like routines for enhanced compatibility
- Floating point math support (IEEE single and double precision or M68881 inline math)
- Thread-safe library variant (when built with `__THREAD_SAFE` preprocessor symbol)
- Socket I/O functions for network programming
- Comprehensive startup code for both SAS/C and GCC
- Replacement libraries for amiga.lib and debug.lib from the NDK

### Is this a fork of clib2? 

Currently no, it is intended that this remains a stable release of the most recent version from Olaf Barthel himself for the time being, without additional contributions and fixes from other clib2 forks. Fixes from other forks may be cherry picked where there is a good reason to do so.

amigazen project efforts are instead focussed on the UniLib3 C library, but clib2 is also provided as part of ToolKit to make it easy to choose between the complete set of options.

There are already several forks of clib2 to be found on places like GitHub. All of these seem to be focussed on GCC specifically, abandoning the SAS/C compatibility. One in particular has changed name to clib4 and is focussed on providing a complete C library for OS4, which is sensible as then efforts can be focussed on that without the need to maintain backwards compatibility.

### Will there be a clib3?

If in the future features of clib4 are backported to clib2 it would make sense to rename it to clib3, not least to make it clear that clib4 is for OS4 and clib3 is for classic Amiga, while the original clib2 remains available should anyone want compatibility with older versions.

### Can clib2 be used with DICE and VBCC compilers too?

It is likely that any compiler supporting the Amiga HUNK .lib format will work but this release has not been tested, and the startup code may need to be reworked.

### Will there be a shared library version of clib2?

There is limited value in making a standard C library a dynamically loaded shared library, as the number of functions included is large, but the number of functions used all the time by most applications is much smaller, meaning you are trading off having the whole library in memory for a small number of functions to be reused, versus having some functions repeated across multiple applications.

### What floating point support does clib2 provide?

For the 68k platform, clib2 supports IEEE single and double precision or M68881 inline math. There is no support for the fast floating point (FFP) format or exclusive IEEE single precision. You either get double precision (IEEE math) or extended precision (M68881 inline math), determined at compile time using the `IEEE_FLOATING_POINT_SUPPORT` or `M68881_FLOATING_POINT_SUPPORT` preprocessor symbols.

For the PowerPC platform, clib2 uses code borrowed from fdlibm 5.3 (a portable library from Sun Microsystems) and supports only double precision floating point numbers according to the IEEE 754 standard.

### Is clib2 thread-safe?

clib2 can be built as a thread-safe library by defining the `__THREAD_SAFE` preprocessor symbol. However, thread-safety does not imply that you can have multiple callers access and close the same file - there is no resource tracking to that degree. The thread-safety primarily prevents issues with simultaneous and overlapping accesses to files, memory allocation, and other resources.

Note that 'thread-safe' does not mean 'reentrant'. Some functions like `mkdtemp()`, `rand()`, and `localtime()` are not thread-safe, but POSIX-compliant thread-safe variants like `rand_r()` and `localtime_r()` are available.

### What are the limitations of clib2?

- Requires AmigaOS 3.1 or higher (no support for Kickstart 1.3 and below)
- Limited support for `amiga.lib` functionality (only `NewList()`, `HookEntry()`, `CallHook()`, `CallHookA()`, `DoMethod()` family, and RexxVars family)
- Exception handling in math code is not particularly effective due to the lack of an exception handler installed by the runtime library
- When using SAS/C, base relative (A4) addressing does not work - use the `data=faronly` option
- Thread-safe library has limitations with `exit()`, `abort()`, `assert()`, and `raise()` functions in child processes

### How does clib2 handle memory allocation?

In the standard `libc.a` implementation, any request to allocate 0 bytes will fail and return `NULL` with `errno` set to `EINVAL`. In the `libunix.a` implementation, a request to allocate 0 bytes will result in an allocation of at least 4 bytes set to zero, with each zero-length allocation returning a different memory address.

### What about documentation and support?

The library code itself is well-documented through comments, and the header files contain information on library behavior beyond just data type and function prototype definitions. The `<dos.h>` header file specifically contains documentation about special libraries and global variables that may be used or replaced by user code.

For comprehensive documentation, consult 'C' - A Reference Manual and the Open Group's Single Unix Specification.

## Contact 

- At GitHub https://github.com/amigazen/toolkit/ 
- on the web at http://www.amigazen.com/ (Amiga browser compatible)
- or email toolkit@amigazen.com

## Acknowledgements

*Amiga* is a trademark of **Amiga Inc**. 