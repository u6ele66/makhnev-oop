#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include <iomanip> 

using namespace std;

const int MATRIX_SIZE = 3;
const int PRECISION = 3;
const int MAX_ARGUMENTS_COUNT = 3;

struct Args
{
    string matrixFilePath1;
    string matrixFilePath2;
};

//	Функция получения данных из аргументов командной строки
optional<Args> GetArgs(int argc, char* argv[])
{
    if (argc != MAX_ARGUMENTS_COUNT)
    {
        ofstream output("output.txt");
        output << "Invalid number of arguments\n";
        cout << "Invalid number of arguments\n";
        output << "Usage: multmatrix.exe <matrix file1> <matrix file2>\n";
        cout << "Usage: multmatrix.exe <matrix file1> <matrix file2>\n";
        return nullopt;
    }
    Args args;
    args.matrixFilePath1 = argv[1];
    args.matrixFilePath2 = argv[2];
    return args;
}

void InitMatrix(double Matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            Matrix[i][j] = 0.000;
        }
    }
}

bool ReadMatrix(double Matrix[MATRIX_SIZE][MATRIX_SIZE], const string& MatrixFilePath)
{
    ifstream matrixFile;
    ofstream output;
    matrixFile.open(MatrixFilePath);
    output.open("output.txt");
    if (!matrixFile.is_open())
    {
        cout << "Failed to open " << MatrixFilePath << " for reading\n";
        output << "Failed to open " << MatrixFilePath << " for reading\n";
        return false;
    }

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (!(matrixFile >> Matrix[i][j]))
            {
                cout << "Incorrect input data\n";
                output << "Incorrect input data\n";
                return false;
            }
        }
    }

    return true;
}

bool PrintMatrix(double Matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    ofstream output;
    output.open("output.txt");
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (!(cout << fixed << setprecision(PRECISION) << Matrix[i][j] << '\t'))
            {
                cout << "Failed to write data to output stream\n";
                output << "Failed to write data to output stream\n";
                return false;
            }
            output << fixed << setprecision(PRECISION) << Matrix[i][j] << '\t';
        }
        if (!(cout << '\n'))
        {
            cout << "Failed to write data to output stream\n";
            output << "Failed to write data to output stream\n";
            return false;
        }
        output << '\n';
    }

    return true;
}

void MultiplyMatrix(const double matrix1[MATRIX_SIZE][MATRIX_SIZE], const double matrix2[MATRIX_SIZE][MATRIX_SIZE], double Result[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                Result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

bool MatrixProcessing(const string& MatrixFilePath1, const string& MatrixFilePath2)
{
    double Matrix1[MATRIX_SIZE][MATRIX_SIZE];
    double Matrix2[MATRIX_SIZE][MATRIX_SIZE];
    double ResultMatrix[MATRIX_SIZE][MATRIX_SIZE];

    InitMatrix(Matrix1);
    InitMatrix(Matrix2);
    InitMatrix(ResultMatrix);

    if (!ReadMatrix(Matrix1, MatrixFilePath1))
    {
        return false;
    }
    if (!ReadMatrix(Matrix2, MatrixFilePath2))
    {
        return false;
    }

    MultiplyMatrix(Matrix1, Matrix2, ResultMatrix);

    if (!PrintMatrix(ResultMatrix))
    {
        return false;
    }
    cout << '\n';

    return true;
}

int main(int argc, char* argv[])
{
    //	Получение данных из аргументов командной строки
    auto args = GetArgs(argc, argv);
    if (args == nullopt)
    {
        return 1;
    }

    if (!MatrixProcessing(args->matrixFilePath1, args->matrixFilePath2))
    {
        return 1;
    }

    return 0;
}