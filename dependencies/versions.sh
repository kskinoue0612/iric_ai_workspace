#!/bin/bash

# All version numbers are stored in versions.cmd
#
# This has a strange syntax and only works in
# Bash/Zsh/Ksh93
# see https://www.shellcheck.net/
# see http://mywiki.wooledge.org/BashFAQ/024

while IFS= read -r line
do
  eval "${line//set/export}"
done < <(grep '^set \(.*\)_VER=\(.*\)' versions.cmd)

if [ -z "$BUILD_TOOLS" ]; then
  export BUILD_TOOLS="OFF"
fi
