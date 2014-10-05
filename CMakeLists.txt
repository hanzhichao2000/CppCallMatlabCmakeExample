PROJECT(CppCallMatlabCmakeExample)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)


SET(TARGET_DIR 
    ${PROJECT_SOURCE_DIR}/demo/for_redistribution_files_only)
SET(TARGET_LIB demo)

IF(NOT TARGET_DIR)
    MESSAGE(FATAL_ERROR "$TARGET_DIR should be defined!")
ENDIF()

IF(NOT TARGET_LIB)
    MESSAGE(FATAL_ERROR "$TARGET_LIB should be defined!")
ENDIF()


SET(CMAKE_CXX_FLAGS "-ansi -pthread")


#####################################################################
# assert env variable
SET(MATLABROOT $ENV{MATLABROOT})
IF(NOT MATLABROOT)
    message(FATAL_ERROR "$MATLABROOT should be defined!")
ENDIF()

#####################################################################
# check os and set arch
IF(UNIX)
    SET(ARCH glnxa64)
    ADD_DEFINITIONS(-D_GNU_SOURCE -DUNIX -DX11 -DGLNXA64 -DGCC)
# ELSEIF(WIN32)
#	SET(ARCH win64()
ELSE()
    MESSAGE(FATAL_ERROR "The current OS is not support yet!")
ENDIF()

#####################################################################
# assert prj is compiled as a matlab library

IF(IS_DIRECTORY ${TARGET_DIR})
    IF(NOT EXISTS "${TARGET_DIR}/lib${TARGET_LIB}.so")
        MESSAGE(FATAL_ERROR
            "lib${TARGET_LIB}.so should be linked to ${TARGET_LIB}.so before cmake!")
    ENDIF()
ELSE()
    MESSAGE(FATAL_ERROR 
        "${TARGET_LIB}.prj should be set up in the current directory and compiled as a Matlab library before cmake!")
ENDIF()

INCLUDE_DIRECTORIES(${MATLABROOT}/extern/include ${TARGET_DIR})
LINK_DIRECTORIES(${MATLABROOT}/runtime/${ARCH} ${TARGET_DIR})


ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main mwmclmcrrt ${TARGET_LIB})
