# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Environment Setup

Run `setup_path.bat` to configure the development environment. This script sets up:
- Node.js environment (`C:\Program Files\nodejs\nodevars.bat`)
- Visual Studio Build Tools x64 environment (`vcvars64.bat`)

This is required before building any native modules or running Node.js tooling.

## Project Status

The `dependencies/` directory contains build scripts for iRIC's dependent libraries (originally from iricdev-2019). These scripts build all C++ libraries required by iRIC on Windows and Linux.

## Building dependent libraries

Dependent libraries are installed in the `dependencies` directory. Build the libraries using CMake, so that this project is OS independent.

In `dependencies` directory, maintain setup.bat so that running the bat file, all the dependent libraries are installed in dependencies directory.

For example, when VTK is needed, add install_vtk.bat, and call it from setup.bat.

In install_vtk.bat, do the following tasks:

1. Check if it is already installed.
2. If not, download it from internet, using curl.
3. Build the library using CMake. If the library does not include CMakeList.txt, try building using Makefile.

## Dependencies Directory Structure

The `dependencies/` directory contains build infrastructure for iRIC's C++ dependent libraries.

### Version and Download Management

- **`versions.cmd`** / **`versions.sh`** / **`versions.ps1`** — Centralized version numbers for all libraries. All build scripts source versions from here.
- **`download.cmd`** / **`download.sh`** / **`download_linux_curl.sh`** — Download source archives for all libraries using `wget` or `curl`, skipping files already present.

### Build Entry Points

- **`iricdev.proj`** — MSBuild project file (Windows). Orchestrates build of all libraries by importing each library's `.targets` file. Run via `msbuild_2019.cmd`.
- **`msbuild_2019.cmd`** / **`msbuild_2019_w_tools.cmd`** — Windows Command Prompt entry points that invoke MSBuild on `iricdev.proj`. The `_w_tools` variant also builds HDF5 tools.
- **`iricdev.mk`** — Makefile entry point for Linux builds.
- **`build_gcc.sh`** / **`build_icc.sh`** — Shell script entry points for GCC and ICC compiler builds on Linux.

### Per-Library Build Files

Each library has two files: a `.cmake` or `.sh` script containing the actual build logic, and a `.targets` file for MSBuild integration (Windows).

| Library | Build Script | MSBuild Targets | Purpose |
|---|---|---|---|
| VTK | `build-vtk.sh` / `vtk.cmake` | `vtk.targets` | 3D visualization toolkit |
| HDF5 | `build-hdf5.sh` / `hdf5.cmake` | `hdf5.targets` | Hierarchical Data Format I/O |
| Poco | `poco.cmake` | `poco.targets` | C++ network/utility framework |

### Post-Build File Generation

- **`create-files.cmd`** / **`create-files.sh`** — Run after all libraries are built; generates `paths.pri` and `dirExt.prop`.
- **`create-paths-pri.cmd`** / **`create-paths-pri.sh`** — Generates `paths.pri` for Qt `.pro` file include paths and library paths.
- **`create-dirExt-prop.cmd`** / **`create-dirExt-prop.sh`** — Generates `dirExt.prop` for MSBuild property sheets.

### Configuration Files

- **`programs_std.prop`** / **`programs.prop`** (user-created copy) — MSBuild properties defining tool paths (cmake, git, curl, 7-zip, etc.). Copy `programs_std.prop` to `programs.prop` and adjust paths before building.
- **`directories.prop`** — MSBuild properties for install/source/download directory paths.
- **`appveyor_programs.prop`** — Tool path overrides for AppVeyor CI environment.
- **`appveyor.yml`** — AppVeyor CI configuration for Windows builds.

### GitHub Actions

- **`.github/workflows/build.yml`** — Primary CI workflow for building all libraries.
- **`.github/workflows/manual.yml`** — Manually triggered workflow for on-demand builds.
- **`init.github_env.sh`** / **`init.github_env.ps1`** — Initialize environment variables for GitHub Actions runners.

### Utilities

- **`cleanup-cache.cmd`** — Clears AppVeyor build cache via REST API.
- **`bom.txt`** — Bill of materials listing library versions.
- **`scripts/Windows/`** — PowerShell scripts for installing Qt via the Qt online installer.
