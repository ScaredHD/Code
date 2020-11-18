#include <iostream>
#include <vector>
#include <initializer_list>
using std::cin;
using std::cout;
using std::endl;


template <typename T>
class Matrix {
public:
    Matrix(unsigned row, unsigned col, T element = 1);
    Matrix(std::initializer_list<std::initializer_list<T>> il);
    size_t rowSize() const { return sz[0]; }
    size_t colSize() const { return sz[1]; }

    std::vector<T> row() const;
    std::vector<T> col() const;

private:
    std::vector<std::vector<T>> mat;
    std::vector<size_t> sz{0, 0};
};


int main()
{
    Matrix<int> mat(3, 4);
    cout << mat.rowSize() << " " << mat.colSize() << endl;
    return 0;
}

template <typename T>
Matrix<T>::Matrix(unsigned row, unsigned col, T elem)
{
    for (size_t i = 0; i != row; i++)
    {
        std::vector<T> v(col, elem);
        mat.push_back(v);
    }
    sz[0] = row;
    sz[1] = col;
}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> il)
{
    
}



