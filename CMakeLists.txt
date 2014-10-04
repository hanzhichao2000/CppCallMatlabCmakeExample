PROJECT(CppCallMatlabCmakeExample)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
ADD_DEFINITIONS(-D_GNU_SOURCE -DUNIX -DX11 -DGLNXA64 -DGCC)

SET(CMAKE_CXX_FLAGS "-ansi -pthread")


#####################################################################
# assert env variable
SET(MATLABROOT $ENV{MATLABROOT})
IF(MATLABROOT)
ELSE()
    message(FATAL_ERROR "$MATLABROOT should be defined!")
ENDIF()

#####################################################################
# check os and set arch
IF(UNIX)
    SET(ARCH glnxa64)
# ELSEIF(WIN32)
#	SET(ARCH win64)
ELSE()
    MESSAGE(FATAL_ERROR "The current OS is not support yet!")
ENDIF()

#####################################################################
# assert prj is compiled as a matlab library
SET(DEMO_DIR 
    ${PROJECT_SOURCE_DIR}/demo/for_redistribution_files_only)
IF(IS_DIRECTORY ${DEMO_DIR})
ELSE()
    MESSAGE(FATAL_ERROR 
        "demo.prj should be set up in the current directory, including demo.m and demo2.m, and compiled as a Matlab library before cmake!")
ENDIF()

INCLUDE_DIRECTORIES(${MATLABROOT}/extern/include ${DEMO_DIR})
LINK_DIRECTORIES(${MATLABROOT}/runtime/${ARCH} ${DEMO_DIR})


ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main libmwmclmcrrt.so demo.so)
