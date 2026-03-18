#!/bin/sh
topdir=$(pwd)
. ./versions.sh
echo "[release]"
echo "hdf5     = ${topdir}/lib/install/hdf5-${HDF5_VER}/release/bin/"
echo "vtk      = ${topdir}/lib/install/VTK-${VTK_VER}/release/bin/"
echo ""
echo "[debug]"
echo "hdf5     = ${topdir}/lib/install/hdf5-${HDF5_VER}/debug/bin/"
echo "vtk      = ${topdir}/lib/install/VTK-${VTK_VER}/debug/bin/"
