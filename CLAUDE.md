# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Environment Setup

Run `setup_path.bat` to configure the development environment. This script sets up:
- Node.js environment (`C:\Program Files\nodejs\nodevars.bat`)
- Visual Studio Build Tools x64 environment (`vcvars64.bat`)

This is required before building any native modules or running Node.js tooling.

## Project Status

This project is in early initialization. The `dependencies/` directory is currently empty and awaiting content.

## Building dependent libraries

Dependent libraries are installed in the `dependencies` directory. Build the libraries using CMake, so that this project is OS independent.

In `dependencies` directory, maintain setup.bat so that running the bat file, all the dependent libraries are installed in dependencies directory.

For example, when VTK is needed, add install_vtk.bat, and call it from setup.bat.

In install_vtk.bat, do the following tasks:

1. Check if it is already installed.
2. If not, download it from internet, using curl.
3. Build the library using CMake. If the library does not include CMakeList.txt, try building using Makefile.
