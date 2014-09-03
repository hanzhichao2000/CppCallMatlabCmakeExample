Introduction
============

An example for cpp code to call Matlab functions, built with CMake in Linux.

Usage
=====

#. Compile demo.m and demo2.m as a matlab library.
   A directory ``demo`` should exist in the current directory.
#. Define an environment variable ``$MATLABROOT`` 
   indicating the root of Matlab, e.g. ``/usr/local/MATLAB/R2014a``.
#. ``mkdir build && cd build && cmake .. && make``
