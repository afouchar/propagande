#include "header_png.h"

void	ft_glitch(t_file *file, FILE **fp)
{
  t_png		pi;
  t_png		np;
  FILE		*nfp;
  png_uint_32	y;

  y = 0;
  pi.sig_read = 8;
  pi.png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  pi.info_ptr = png_create_info_struct(pi.png_ptr);
  if (setjmp(png_jmpbuf(pi.png_ptr)) || !pi.png_ptr || !pi.info_ptr)
    ft_error(file, 10);

  png_init_io(pi.png_ptr, *fp);
  png_set_sig_bytes(pi.png_ptr, pi.sig_read);
  png_read_info(pi.png_ptr, pi.info_ptr);
  //invalid HIDR ??
  //height = 0 in HIDR ??
  png_get_IHDR(pi.png_ptr, pi.info_ptr, &pi.width, &pi.height, &pi.bit_depth, &pi.color_type,
		&pi.interlace_type, NULL, NULL);	

  pi.width = png_get_image_width(pi.png_ptr, pi.info_ptr);
  pi.height = png_get_image_height(pi.png_ptr, pi.info_ptr);
  pi.color_type = png_get_color_type(pi.png_ptr, pi.info_ptr);
  pi.bit_depth = png_get_bit_depth(pi.png_ptr, pi.info_ptr);

  png_read_update_info(pi.png_ptr, pi.info_ptr);

  if (setjmp(png_jmpbuf(pi.png_ptr)))
    ft_error(file, 10);

  pi.row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * pi.height);
   while(y < pi.height)
     {
       pi.row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(pi.png_ptr,pi.info_ptr));
       y++;
     }
   y = 0;
  png_read_image(pi.png_ptr, pi.row_pointers);
  fclose(*fp);



  nfp = fopen(file->new_file_name, "wb");
  np.png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  np.info_ptr = png_create_info_struct(pi.png_ptr);
  if (setjmp(png_jmpbuf(np.png_ptr)) || !np.png_ptr || !np.info_ptr || !nfp)
    ft_error(file, 11);

  png_init_io(np.png_ptr, nfp);

  if (setjmp(png_jmpbuf(np.png_ptr)))
    ft_error(file, 11);

  png_set_IHDR(np.png_ptr, np.info_ptr, np.width, np.height,
	       np.bit_depth, np.color_type, PNG_INTERLACE_NONE,
	       PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
  png_write_info(np.png_ptr, np.info_ptr);

  if (setjmp(png_jmpbuf(np.png_ptr)))
    ft_error(file, 11);

  png_write_info(np.png_ptr, np.info_ptr);

  if (setjmp(png_jmpbuf(np.png_ptr)))
    ft_error(file, 11);

  png_write_image(np.png_ptr, np.row_pointers);

  if (setjmp(png_jmpbuf(np.png_ptr)))
    ft_error(file, 11);

  png_write_end(np.png_ptr, NULL);

  np.row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * np.height);
  while (y < np.height)
    {
      free(np.row_pointers[y]);
      y++;
    }
  free(np.row_pointers);

  *fp = nfp;
  fclose(nfp);
}
