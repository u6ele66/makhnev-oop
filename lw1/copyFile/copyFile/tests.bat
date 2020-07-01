
rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem проверяем копирование пустого файла (копируем его во временную папку текущего пользователя)
%PROGRAM% empty.txt C:\Users\Lenovo\source\repos\copyFile\copyFile\empty.txt || goto err
fc.exe C:\Users\Lenovo\source\repos\copyFile\copyFile\empty.txt empty.txt || goto err
echo Test 1 successful 

rem проверяем копирование файла из одной строки
%PROGRAM% one-line.txt C:\Users\Lenovo\source\repos\copyFile\copyFile\one-line.txt || goto err
fc.exe C:\Users\Lenovo\source\repos\copyFile\copyFile\one-line.txt one-line.txt || goto err
echo Test 2 successful

rem проверяем копирование файла из нескольких строк
%PROGRAM% multiline.txt C:\Users\Lenovo\source\repos\copyFile\copyFile\multiline.txt || goto err
fc.exe C:\Users\Lenovo\source\repos\copyFile\copyFile\multiline.txt multiline.txt || goto err
echo Test 3 successful

rem ожидаем ненулевой код ошибки при копировании несуществующего файла
%PROGRAM% non-existing-file-name.txt C:\Users\Lenovo\source\repos\copyFile\copyFile\non-existing-file-name.txt || goto err
echo Test 4 successful

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1