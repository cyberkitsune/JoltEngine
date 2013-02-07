#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/JoltRender.o \
	${OBJECTDIR}/src/JoltLoop.o \
	${OBJECTDIR}/src/JoltCleanup.o \
	${OBJECTDIR}/src/DrawMacros.o \
	${OBJECTDIR}/src/JoltDataFile.o \
	${OBJECTDIR}/src/JoltApp.o \
	${OBJECTDIR}/src/JoltInit.o \
	${OBJECTDIR}/src/JoltAnimation.o \
	${OBJECTDIR}/src/JoltMap.o \
	${OBJECTDIR}/src/JoltTile.o \
	${OBJECTDIR}/src/JoltEvent.o \
	${OBJECTDIR}/src/JoltConsole.o \
	${OBJECTDIR}/src/JoltEntity.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs sdl`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/joltengine

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/joltengine: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/joltengine ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/JoltRender.o: src/JoltRender.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltRender.o src/JoltRender.cpp

${OBJECTDIR}/src/JoltLoop.o: src/JoltLoop.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltLoop.o src/JoltLoop.cpp

${OBJECTDIR}/src/JoltCleanup.o: src/JoltCleanup.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltCleanup.o src/JoltCleanup.cpp

${OBJECTDIR}/src/DrawMacros.o: src/DrawMacros.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/DrawMacros.o src/DrawMacros.cpp

${OBJECTDIR}/src/JoltDataFile.o: src/JoltDataFile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltDataFile.o src/JoltDataFile.cpp

${OBJECTDIR}/src/JoltApp.o: src/JoltApp.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltApp.o src/JoltApp.cpp

${OBJECTDIR}/src/JoltInit.o: src/JoltInit.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltInit.o src/JoltInit.cpp

${OBJECTDIR}/src/JoltAnimation.o: src/JoltAnimation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltAnimation.o src/JoltAnimation.cpp

${OBJECTDIR}/src/JoltMap.o: src/JoltMap.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltMap.o src/JoltMap.cpp

${OBJECTDIR}/src/JoltTile.o: src/JoltTile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltTile.o src/JoltTile.cpp

${OBJECTDIR}/src/JoltEvent.o: src/JoltEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltEvent.o src/JoltEvent.cpp

${OBJECTDIR}/src/JoltConsole.o: src/JoltConsole.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltConsole.o src/JoltConsole.cpp

${OBJECTDIR}/src/JoltEntity.o: src/JoltEntity.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/JoltEntity.o src/JoltEntity.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/joltengine

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
