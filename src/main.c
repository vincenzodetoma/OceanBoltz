#include "main.h"

int main(int argc, char **argv){
  int i;
  read_params();
  check_symmetry();
  deallocations();
  return EXIT_SUCCESS;
}
