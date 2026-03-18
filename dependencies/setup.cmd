@echo off
setlocal enableextensions
call versions.cmd
set GENERATOR="Visual Studio 18 2026"
set SGEN=vs2026-x64
msbuild -noLogo -maxCpuCount -v:d -p:UseDeps=Yes -target:all iricdev.proj
endlocal
