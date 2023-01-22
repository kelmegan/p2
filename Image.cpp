// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Image.h"

// REQUIRES: img points to an Image
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, int width, int height) {
  assert(0 < width && width <= MAX_MATRIX_WIDTH); 
  assert(0 < height && height <= MAX_MATRIX_HEIGHT);
  img->width = width;
  img->height = height;
  img->blue_channel.width = width;
  img->red_channel.width = width;
  img->green_channel.width = width;
  img->blue_channel.height = height;
  img->red_channel.height = height;
  img->green_channel.height = height;


}

// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, std::istream& is) {
  assert(false); // TODO Replace with your implementation!
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Writes the image to the given output stream in PPM format.
//           You must use the kind of whitespace specified here.
//           First, prints out the header for the image like this:
//             P3 [newline]
//             WIDTH [space] HEIGHT [newline]
//             255 [newline]
//           Next, prints out the rows of the image, each followed by a
//           newline. Each pixel in a row is printed as three ints
//           for its red, green, and blue components, in that order. Each
//           int is followed by a space. This means that there will be an
//           "extra" space at the end of each line. See the project spec
//           for an example.
void Image_print(const Image* img, std::ostream& os) {
  assert(false); // TODO Replace with your implementation!
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image* img) {
  assert(img->width == Matrix_width(&(img->blue_channel)) && img->width == Matrix_width(&(img->green_channel)) && img->width == Matrix_width(&(img->green_channel)));
  assert(img->height == Matrix_height(&(img->blue_channel)) && img->height == Matrix_height(&(img->green_channel)) && img->height == Matrix_height(&(img->green_channel)));
   return img->width;
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image* img) {
  assert(img->width == Matrix_width(&(img->blue_channel)) && img->width == Matrix_width(&(img->green_channel)) && img->width == Matrix_width(&(img->green_channel)));
  assert(img->height == Matrix_height(&(img->blue_channel)) && img->height == Matrix_height(&(img->green_channel)) && img->height == Matrix_height(&(img->green_channel)));
  return img->height;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image* img, int row, int column) {
  assert(img->width == Matrix_width(&(img->blue_channel)) && img->width == Matrix_width(&(img->green_channel)) && img->width == Matrix_width(&(img->green_channel)));
  assert(img->height == Matrix_height(&(img->blue_channel)) && img->height == Matrix_height(&(img->green_channel)) && img->height == Matrix_height(&(img->green_channel)));
  assert(0 <= row && row < Image_height(img));
  assert(0 <= column && column < Image_width(img));
  Pixel pineapple;
  pineapple.r = *(Matrix_at(&(img->red_channel), row, column));
  pineapple.b = *(Matrix_at(&(img->blue_channel), row, column));
  pineapple.g = *(Matrix_at(&(img->green_channel), row, column));
  return pineapple;

}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// MODIFIES: *img
// EFFECTS:  Sets the pixel in the Image at the given row and column
//           to the given color.
void Image_set_pixel(Image* img, int row, int column, Pixel color) {
  assert(img->width == Matrix_width(&(img->blue_channel)) && img->width == Matrix_width(&(img->green_channel)) && img->width == Matrix_width(&(img->green_channel)));
  assert(img->height == Matrix_height(&(img->blue_channel)) && img->height == Matrix_height(&(img->green_channel)) && img->height == Matrix_height(&(img->green_channel)));
  assert(0 <= row && row < Image_height(img));
  assert(0 <= column && column < Image_width(img));
  assert(0 <= color.r && color.r <= 255);
  assert(0 <= color.b && color.b <= 255);
  assert(0 <= color.g && color.g <= 255);
  *(Matrix_at(&(img->red_channel), row, column)) = color.r;
  *(Matrix_at(&(img->blue_channel), row, column)) = color.b;
  *(Matrix_at(&(img->green_channel), row, column)) = color.g;
}

// REQUIRES: img points to a valid Image
// MODIFIES: *img
// EFFECTS:  Sets each pixel in the image to the given color.
void Image_fill(Image* img, Pixel color) {
  assert(img->width == Matrix_width(&(img->blue_channel)) && img->width == Matrix_width(&(img->green_channel)) && img->width == Matrix_width(&(img->green_channel)));
  assert(img->height == Matrix_height(&(img->blue_channel)) && img->height == Matrix_height(&(img->green_channel)) && img->height == Matrix_height(&(img->green_channel)));
  assert(0 <= color.r && color.r <= 255);
  assert(0 <= color.b && color.b <= 255);
  assert(0 <= color.g && color.g <= 255);
  Matrix_fill(&(img->blue_channel),color.b);
  Matrix_fill(&(img->red_channel),color.r);
  Matrix_fill(&(img->green_channel),color.g);
}
