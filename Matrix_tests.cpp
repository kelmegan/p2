// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.


// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.
TEST(test_matrix_fill) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(test_matrix_init_1) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 500 , 500);
  ASSERT_EQUAL(Matrix_height(mat), 500);
  ASSERT_EQUAL(Matrix_width(mat), 500);
  delete mat;
}

TEST(test_matrix_width) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 200, 150);

  ASSERT_EQUAL(Matrix_width(mat), 200);
  delete mat;
}
TEST(test_matrix_height) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 200, 150);
  ASSERT_EQUAL(Matrix_height(mat), 150);
  delete mat;
}
TEST(test_matrix_rowcol) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 200, 150);
  Matrix_fill(mat, 15);

  int *ptr = Matrix_at(mat, 100, 37);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 100);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 37);
  ASSERT_EQUAL(*ptr, 15);
  delete mat;
}
TEST(test_matrix_pointer) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 200, 150);
  Matrix_fill(mat, 15);
  int *ptr = Matrix_at(mat, 100, 37);
  *ptr = 420;

  const int *cptr = Matrix_at(mat, 100, 37);
  ASSERT_EQUAL(*cptr, 420);

  //Matrix_fill_border(mat, 2);
  //ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 2);

  //ASSERT_EQUAL(Matrix_max(mat), 42);

  delete mat;
}
TEST(test_matrix_border) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 200, 150);
  Matrix_fill(mat, 15);
  int *ptr = Matrix_at(mat, 100, 37);
  *ptr = 420;

  const int *cptr = Matrix_at(mat, 100, 37);
  ASSERT_EQUAL(*cptr, 420);

  Matrix_fill_border(mat, 2);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 2);

  ASSERT_EQUAL(Matrix_max(mat), 420);

  delete mat;
}

TEST(test_matrix_border_large) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 500, 500);
  Matrix_fill(mat, 255);
  int *ptr = Matrix_at(mat, 499, 499);
  *ptr = 3;

  const int *cptr = Matrix_at(mat, 499, 499);

  ASSERT_EQUAL(*cptr, 3);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 499, 0, 500), 499);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 499, 0, 500), 3);
  Matrix_fill_border(mat, 60);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 60);

  ASSERT_EQUAL(*Matrix_at(mat, 0, 499), 60);
  ASSERT_EQUAL(*Matrix_at(mat, 499, 0), 60);
  ASSERT_EQUAL(*Matrix_at(mat, 499, 499), 60);


  delete mat;
}

TEST(test_matrix_border_3x3) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 3);
  Matrix_fill(mat, 0);
  int *ptr = Matrix_at(mat, 1, 1);
  *ptr = 30;
  const int *cptr = Matrix_at(mat, 1, 1);
  ASSERT_EQUAL(*cptr, 30);
  Matrix_fill_border(mat, 500);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 500);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 500);
  ASSERT_EQUAL(*Matrix_at(mat, 2, 2), 500);
  ASSERT_EQUAL(*Matrix_at(mat, 1, 0), 500);
  ASSERT_EQUAL(*Matrix_at(mat, 2, 0), 500);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 2), 500);
  delete mat;
}

TEST(test_mincolinrow_large) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 500, 500);
  Matrix_fill(mat, 50);
  int *ptr = Matrix_at(mat, 25, 25);
  *ptr = 30;
  const int *cptr = Matrix_at(mat, 25, 25);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 25, 0, 50), 25);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 25, 0, 50), 30);
  ASSERT_EQUAL(*cptr, 30);
  delete mat;
}
TEST(test_mincolinrow_small) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 3);
  Matrix_fill(mat, 10);
  int *ptr = Matrix_at(mat, 1, 1);
  *ptr = 9;
  const int *cptr = Matrix_at(mat, 1, 1);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 2), 1);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 2), 9);
  ASSERT_EQUAL(*cptr, 9);
  delete mat;
}

TEST(test_mincolinrow_2x2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 2, 2);
  Matrix_fill(mat, 10);
  int *ptr = Matrix_at(mat, 1, 1);
  *ptr = 9;
  const int *cptr = Matrix_at(mat, 1, 1);
  ASSERT_EQUAL(*cptr, 9);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 1), 1);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 1), 9);
  delete mat;
}

TEST(test_matrix_border_2x2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 2, 2);
  Matrix_fill(mat, 1500);
  int *ptr = Matrix_at(mat, 1, 1);
  *ptr = 1499;
  const int *cptr = Matrix_at(mat, 1, 1);
  ASSERT_EQUAL(*cptr, 1499);
  Matrix_fill_border(mat, 500);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 500);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 1), 500);
  ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 500);
  ASSERT_EQUAL(*Matrix_at(mat, 1, 0), 500);
  delete mat;
}

TEST(test_matrix_border_1x1) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, 0);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 0);
  int *ptr = Matrix_at(mat, 0, 0);
  *ptr = 30;
  const int *cptr = Matrix_at(mat, 0, 0);
  ASSERT_EQUAL(*cptr, 30);
  Matrix_fill_border(mat, 500);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 500);
  delete mat;
}

TEST(test_mincolinrow_2x1) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 2, 1);
  Matrix_fill(mat, 10);
  int *ptr = Matrix_at(mat, 0, 0);
  *ptr = 9;
  const int *cptr = Matrix_at(mat, 0, 0);
  ASSERT_EQUAL(*cptr, 9);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 1), 0);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 1), 9);
  delete mat;
}

TEST(test_matrix_border_2x1) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 2, 1);
  Matrix_fill(mat, 7);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 1), 7);
  int *ptr = Matrix_at(mat, 0, 0);
  *ptr = 30;
  const int *cptr = Matrix_at(mat, 0, 0);
  ASSERT_EQUAL(*cptr, 30);
  Matrix_fill_border(mat, 500);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 500);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 1), 500);
  delete mat;
}


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
