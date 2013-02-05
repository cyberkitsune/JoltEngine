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
	${OBJECTDIR}/JoltApp.o \
	${OBJECTDIR}/JoltEvent.o \
	${OBJECTDIR}/JoltInit.o \
	${OBJECTDIR}/JoltDataFile.o \
	${OBJECTDIR}/JoltConsole.o


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

${OBJECTDIR}/JoltApp.o: JoltApp.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/JoltApp.o JoltApp.cpp

${OBJECTDIR}/JoltEvent.o: JoltEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/JoltEvent.o JoltEvent.cpp

${OBJECTDIR}/JoltInit.o: JoltInit.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/JoltInit.o JoltInit.cpp

${OBJECTDIR}/JoltDataFile.o: JoltDataFile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/JoltDataFile.o JoltDataFile.cpp

${OBJECTDIR}/JoltConsole.o: JoltConsole.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags sdl`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/JoltConsole.o JoltConsole.cpp

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
