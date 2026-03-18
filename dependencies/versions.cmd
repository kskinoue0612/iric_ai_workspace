@echo off
::
:: versions.cmd
::

set HDF5_VER=1.14.6
set HDF5_MAJMIN_V=v1_14
set HDF5_VER_V=v1_14_6
set POCO_VER=1.14.2
set VTK_VER=9.5.2

if NOT defined BUILD_TOOLS  set BUILD_TOOLS=OFF

:: nmake cannot create environment variables
if NOT defined GENERATOR    set GENERATOR="Visual Studio 18 2026"
if NOT defined SGEN         set SGEN=vs2026-x64
set VERSIONS_CMD_RUN=YES
