#ifndef __ipnis_priv_h
#define __ipnis_priv_h 1

#include ipnis

/***
/* macros
*/

#define MAKE_FIXED_DESCRIP( list, num_bytes, d_list )\
  d_list.dsc$w_length = num_bytes;\
  d_list.dsc$b_dtype = 14;\
  d_list.dsc$b_class = 1;\
  d_list.dsc$a_pointer = list;

#endif
