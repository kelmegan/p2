// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Image.h"

// REQUIRES: img points to an Image
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image *img, int width, int height) {
   assert(img!=nullptr);
  img->width = width;
  img->height = height;
  Matrix_init(&(img->blue_channel), width, height);
  Matrix_init(&(img->red_channel), width, height);
  Matrix_init(&(img->green_channel), width, height);
}
// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image *img, std::istream &is) {
  char c;
  int w, h, maxintensity;
   assert(img!=nullptr);
  is >> c;
   // assert('P' == c);
  is >> c;
   // assert('3' == c);
  is >> w;
  is >> h;
  // assert w,h is check in matrix init
  Image_init(img, w, h);
  is >> maxintensity;
   assert(maxintensity == 255);
   int r = 0, col = 0,red,green,blue;
   while ((r < h) && is >> red >> green >> blue){
       assert(0<=red && red<=255);
       *Matrix_at(&(img->red_channel), r, col)= red;
       assert(0<=green && green<=255);
       *Matrix_at(&(img->green_channel), r, col)= green;
       assert(0<=blue && blue<=255);
       *Matrix_at(&(img->blue_channel), r, col)= blue;
      if (col == img->width - 1) {
      r++;
      col = 0;
      } else
      col++;
  }
   //std::cout <<r<<" "<<h<<" "<<col<<" "<<w<<" \n";
   assert(r==h && col==0);
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
void Image_print(const Image *img, std::ostream &os) {

   assert(img!=nullptr);
   assert(img->width == Matrix_width(&(img->red_channel)));
   assert(img->width == Matrix_width(&(img->green_channel)));
   assert(img->width == Matrix_width(&(img->blue_channel)));
   assert(img->height == Matrix_height(&(img->red_channel)));
   assert(img->height == Matrix_height(&(img->green_channel)));
   assert(img->height == Matrix_height(&(img->blue_channel)));
  os << "P3" << std::endl;
  os << img->width << " " << img->height << std::endl;
  os << 255 << std::endl;
   for (int row = 0; row < img->height; row++) {
      for (int col = 0; col < img->width; col++) {
         os << *(Matrix_at(&(img->red_channel), row, col)) << " "
            << *(Matrix_at(&(img->green_channel), row, col)) << " "
            << *(Matrix_at(&(img->blue_channel), row, col)) << " ";
    }
    os << std::endl;
  }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image *img) {
   assert(img!=nullptr);
   assert(img->width == Matrix_width(&(img->red_channel)));
   assert(img->width == Matrix_width(&(img->green_channel)));
   assert(img->width == Matrix_width(&(img->blue_channel)));
   assert(img->height == Matrix_height(&(img->red_channel)));
   assert(img->height == Matrix_height(&(img->green_channel)));
   assert(img->height == Matrix_height(&(img->blue_channel)));
  return img->width;
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image *img) {
   assert(img!=nullptr);
   assert(img->width == Matrix_width(&(img->red_channel)));
   assert(img->width == Matrix_width(&(img->green_channel)));
   assert(img->width == Matrix_width(&(img->blue_channel)));
   assert(img->height == Matrix_height(&(img->red_channel)));
   assert(img->height == Matrix_height(&(img->green_channel)));
   assert(img->height == Matrix_height(&(img->blue_channel)));
  return img->height;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image *img, int row, int column) {
   assert(img!=nullptr);
   assert(img->width == Matrix_width(&(img->red_channel)));
   assert(img->width == Matrix_width(&(img->green_channel)));
   assert(img->width == Matrix_width(&(img->blue_channel)));
   assert(img->height == Matrix_height(&(img->red_channel)));
   assert(img->height == Matrix_height(&(img->green_channel)));
   assert(img->height == Matrix_height(&(img->blue_channel)));
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
void Image_set_pixel(Image *img, int row, int column, Pixel color) {
   assert(img!=nullptr);
   assert(img->width == Matrix_width(&(img->red_channel)));
   assert(img->width == Matrix_width(&(img->green_channel)));
   assert(img->width == Matrix_width(&(img->blue_channel)));
   assert(img->height == Matrix_height(&(img->red_channel)));
   assert(img->height == Matrix_height(&(img->green_channel)));
   assert(img->height == Matrix_height(&(img->blue_channel)));
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
void Image_fill(Image *img, Pixel color) {
   assert(img!=nullptr);
   assert(img->width == Matrix_width(&(img->red_channel)));
   assert(img->width == Matrix_width(&(img->green_channel)));
   assert(img->width == Matrix_width(&(img->blue_channel)));
   assert(img->height == Matrix_height(&(img->red_channel)));
   assert(img->height == Matrix_height(&(img->green_channel)));
   assert(img->height == Matrix_height(&(img->blue_channel)));
    assert(0 <= color.r && color.r <= 255);
    assert(0 <= color.b && color.b <= 255);
    assert(0 <= color.g && color.g <= 255);
  Matrix_fill(&(img->blue_channel), color.b);
  Matrix_fill(&(img->red_channel), color.r);
  Matrix_fill(&(img->green_channel), color.g);
}
