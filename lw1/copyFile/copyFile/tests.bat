
rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��������� ����������� ������� ����� (�������� ��� �� ��������� ����� �������� ������������)
%PROGRAM% empty.txt C:\Users\Lenovo\source\repos\copyFile\copyFile\empty.txt || goto err
fc.exe C:\Users\Lenovo\source\repos\copyFile\copyFile\empty.txt empty.txt || goto err
echo Test 1 successful 

rem ��������� ����������� ����� �� ����� ������
%PROGRAM% one-line.txt C:\Users\Lenovo\source\repos\copyFile\copyFile\one-line.txt || goto err
fc.exe C:\Users\Lenovo\source\repos\copyFile\copyFile\one-line.txt one-line.txt || goto err
echo Test 2 successful

rem ��������� ����������� ����� �� ���������� �����
%PROGRAM% multiline.txt C:\Users\Lenovo\source\repos\copyFile\copyFile\multiline.txt || goto err
fc.exe C:\Users\Lenovo\source\repos\copyFile\copyFile\multiline.txt multiline.txt || goto err
echo Test 3 successful

rem ������� ��������� ��� ������ ��� ����������� ��������������� �����
%PROGRAM% non-existing-file-name.txt C:\Users\Lenovo\source\repos\copyFile\copyFile\non-existing-file-name.txt || goto err
echo Test 4 successful

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1