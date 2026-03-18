@echo off
setlocal
set topdir=%~dp0
set topdir=%topdir:\=/%
call versions.cmd
@echo.[release]
@echo.hdf5     = %topdir%lib/install/hdf5-%HDF5_VER%/bin/
@echo.poco     = %topdir%lib/install/poco-%POCO_VER%/bin/
@echo.vtk      = %topdir%lib/install/VTK-%VTK_VER%/release/bin/
@echo.
@echo.[debug]
@echo.hdf5     = %topdir%lib/install/hdf5-%HDF5_VER%/bin/
@echo.poco     = %topdir%lib/install/poco-%POCO_VER%/bin/
if "%DEBUG_LEAKS%"=="YES" (
  @echo.vtk      = %topdir%lib/install/VTK-%VTK_VER%/debug-vtk-leaks/bin/
) else (
  @echo.vtk      = %topdir%lib/install/VTK-%VTK_VER%/debug/bin/
)
