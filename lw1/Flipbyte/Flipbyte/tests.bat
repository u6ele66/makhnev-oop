@echo off

SET Program="%~1"

if %Program%=="" (
	echo Please specify path to program Flipbyte.exe
	exit /B 1
)

REM Input file doesnt exists
%Program% "abc123.txt" "%TEMP%\byte-output.txt" && goto err
echo Test #1 passed!

REM Input line is string
%Program% "input2.txt" "%TEMP%\byte-output.txt" && goto err
echo Test #2 passed!

REM Correct input
%Program% "input3.txt" "%TEMP%\byte-output.txt" || goto err
fc "output3.txt" "%TEMP%\byte-output.txt" > nul || goto err
echo Test #3 passed!

REM Input number bigger than 255
%Program% "input4.txt" "%TEMP%\byte-output.txt" && goto err
echo Test #4 passed!

REM Input number less than 0
%Program% "input5.txt" "%TEMP%\byte-output.txt" && goto err
echo Test #5 passed!

REM Input line is empty
%Program% "input6.txt" "%TEMP%\byte-output.txt" && goto err
echo Test #6 passed!

REM Correct input
%Program% "input7.txt" "%TEMP%\byte-output.txt" || goto err
fc "output7.txt" "%TEMP%\byte-output.txt" > nul || goto err
echo Test #7 passed!

REM Correct input
%Program% "input8.txt" "%TEMP%\byte-output.txt" || goto err
fc "output8.txt" "%TEMP%\byte-output.txt" > nul || goto err
echo Test #8 passed!

REM Tests passed successfully
echo All tests passed successfully
exit /B 0

REM Test failed
:err
echo Test failed!
exit /B 1