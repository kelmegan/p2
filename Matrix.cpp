// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Matrix.h"

// REQUIRES: mat points to a Matrix
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *mat
// EFFECTS:  Initializes *mat as a Matrix with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Matrix_init(Matrix *mat, int width, int height)
{
  assert(0 < width && width <= MAX_MATRIX_WIDTH);
  assert(0 < height && height <= MAX_MATRIX_HEIGHT);
  mat->width = width;
  mat->height = height;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//             WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix *mat, std::ostream &os)
{
  assert(mat!=nullptr);
  assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
  assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
  os << (mat->width) << " ";
  os << (mat->height) << std::endl;
  for (int r = 0; r < mat->height; r++)
  {
    for (int c = 0; c < mat->width; c++)
    {
      os << mat->data[(r * mat->width) + c] << " ";
    }
    os << std::endl;
  }
}

// REQUIRES: mat points to an valid Matrix
// EFFECTS:  Returns the width of the Matrix.
int Matrix_width(const Matrix *mat)
{
  assert(mat!=nullptr);
  assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
  assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
  return mat->width;
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the height of the Matrix.
int Matrix_height(const Matrix *mat)
{
  assert(mat!=nullptr);
  assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
  assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
  return mat->height;
}

// REQUIRES: mat points to a valid Matrix
//           ptr points to an element in the Matrix
// EFFECTS:  Returns the row of the element pointed to by ptr.
int Matrix_row(const Matrix *mat, const int *ptr)
{
  assert(mat!=nullptr);
  assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
  assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
  // int index = ptr-&(mat->data[0]);
  int index = ptr - mat->data;
  assert(0 < index && (index <= (MAX_MATRIX_HEIGHT * MAX_MATRIX_WIDTH)));
  return index / (mat->width);
}

// REQUIRES: mat points to a valid Matrix
//           ptr point to an element in the Matrix
// EFFECTS:  Returns the column of the element pointed to by ptr.
int Matrix_column(const Matrix *mat, const int *ptr)
{
  assert(mat!=nullptr);
  assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
  assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
  int index = ptr - mat->data;
  assert(0 < index && (index <= (MAX_MATRIX_HEIGHT * MAX_MATRIX_WIDTH)));
  return index % (mat->width);
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
int *Matrix_at(Matrix *mat, int row, int column)
{
  assert(mat!=nullptr);
  assert(0 <= row && row < mat->height && row < MAX_MATRIX_HEIGHT);
  assert(0 <= column && column < mat->width && column < MAX_MATRIX_WIDTH);
  return &(mat->data[(row * mat->width) + column]);
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const int *Matrix_at(const Matrix *mat, int row, int column)
{
  assert(mat!=nullptr);
  assert(0 <= row && row < mat->height && row < MAX_MATRIX_HEIGHT);
  assert(0 <= column && column < mat->width && column < MAX_MATRIX_WIDTH);
  //assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
  //assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
  //assert(0 <= row && row < Matrix_height(mat));
  //assert(0 <= column && column < Matrix_width(mat));
  const int *tempInt = &(mat->data[(row * mat->width) + column]);
  return tempInt;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix *mat, int value)
{
  assert(mat!=nullptr);
  //assert(0 <=value && value <=255); //used for energy >255
  assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
  assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
  for (int r = 0; r < mat->height; r++)
  {
    for (int c = 0; c < mat->width; c++)
    {
      mat->data[(r * mat->width) + c] = value;
    }
  }
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix *mat, int value)
{
  assert(mat!=nullptr);
  //assert(0 <=value && value <=255); //used for energy >255
  assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
  assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
  for (int c = 0; c < mat->width; c++)
  {
    mat->data[c] = value;
    mat->data[c + (mat->width * (mat->height - 1))] = value;
  }
  for (int r = 0; r < mat->height; r++)
  {
    mat->data[mat->width * r] = value;
    mat->data[mat->width * r + (mat->width - 1)] = value;
  }
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the value of the maximum element in the Matrix
int Matrix_max(const Matrix *mat)
{
  assert(mat!=nullptr);
  assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
  assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
  int max = mat->data[0];
  for (int r = 0; r < mat->height; r++)
  {
    for (int c = 0; c < mat->width; c++)
    {
      if (mat->data[(mat->width * r) + c] > max)
      {
        max = mat->data[(mat->width * r) + c];
      }
    }
  }
  return max;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the column of the element with the minimal value
//           in a particular region. The region is defined as elements
//           in the given row and between column_start (inclusive) and
//           column_end (exclusive).
//           If multiple elements are minimal, returns the column of
//           the leftmost one.
int Matrix_column_of_min_value_in_row(const Matrix *mat, int row,
                                      int column_start, int column_end)
{
  assert(mat!=nullptr);
  assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
  assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
  assert(0 <= column_start && column_end <= mat->width);
  assert(0 <= row && row < mat->height);
  assert(column_start < column_end);
  int minCol = column_start + 1;
  int min = mat->data[column_start + ((row * Matrix_width(mat)))];
  for (int c = column_start + 2; (c) <= (column_end + 1); c++)
  {
    if (mat->data[c + (row * Matrix_width(mat)) - 1] < min)
    {
      min = mat->data[c + (row * Matrix_width(mat)) - 1];
      minCol = c;
    }
  }
  return minCol - 1;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the minimal value in a particular region. The region
//           is defined as elements in the given row and between
//           column_start (inclusive) and column_end (exclusive).
int Matrix_min_value_in_row(const Matrix *mat, int row,
                            int column_start, int column_end)
{
  assert(mat!=nullptr);
  assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
  assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
  assert(0 <= column_start && column_end <= mat->width);
  assert(0 <= row && row < mat->height);
  
  assert(column_start < column_end);
  int min = mat->data[column_start + ((row * Matrix_width(mat)))];
  for (int c = column_start + 2; (c) <= (column_end + 1); c++)
  {
    if (mat->data[c + (row * Matrix_width(mat)) - 1] < min)
    {
      min = mat->data[c + (row * Matrix_width(mat)) - 1];
    }
  }
  return min;
}
