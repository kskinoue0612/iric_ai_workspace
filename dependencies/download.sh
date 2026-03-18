#!/bin/bash
. ./versions.sh

if [ ! -f "VTK-${VTK_VER}.tar.gz" ]; then
  MAJOR=$(echo ${VTK_VER} | cut -d '.' -f 1)
  MINOR=$(echo ${VTK_VER} | cut -d '.' -f 2)
  wget --no-check-certificate http://www.vtk.org/files/release/${MAJOR}.${MINOR}/VTK-${VTK_VER}.tar.gz
fi

if [ ! -f "hdf5-${HDF5_VER}.tar.gz" ]; then
  MAJOR=$(echo ${HDF5_VER} | cut -d '.' -f 1)
  MINOR=$(echo ${HDF5_VER} | cut -d '.' -f 2)
  wget --no-check-certificate https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-${MAJOR}.${MINOR}/hdf5-${HDF5_VER}/cmake/SZip.tar.gz
  wget --no-check-certificate https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-${MAJOR}.${MINOR}/hdf5-${HDF5_VER}/cmake/ZLib.tar.gz
  wget --no-check-certificate https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-${MAJOR}.${MINOR}/hdf5-${HDF5_VER}/src/hdf5-${HDF5_VER}.tar.gz
fi
