# include "all.h"

void clean_screen(){
#if defined (_WIN64)
  system("cls");
#else
  system("clear");
#endif
}
