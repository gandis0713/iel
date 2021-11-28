
if exist build rmdir build /s /q
mkdir build
cd build
call cmake ..

set VS150TOOL="%VS150COMNTOOLS%\VsDevCmd.bat"
if not exist %VS150TOOL% goto Abort

call %VS150TOOL%
msbuild iel.sln /p:configuration=release

:End
	exit /b 0

:Abort
	echo "Can't find VsDevCmd.bat"
	exit /b -1