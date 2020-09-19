#include "my_reads.h"

void read_params(){
  FILE *fp;
  char *filename= "param.in";
  double *values;
  int len_vals, i;
  char ImHere;
  if ((fp=fopen(filename, "r")) == NULL){
    printf("File %s not opened\n", filename);
    exit(EXIT_FAILURE);
  }
  len_vals = line_count(fp, filename)-1;
  i=0;
  if ((values=(double *)calloc(len_vals, sizeof(double)))==NULL) {
    printf("allocation of initial params failed \n");
    exit(EXIT_FAILURE);
  }
  while ((ImHere = fgetc(fp)) != EOF){
    fscanf(fp, "%*s %lf", &values[i]);
    i++;
  }
  lattice_nx = (int)values[0];
  lattice_ny = (int)values[1];
  lattice_nz = (int)values[2];
  time_step_dt = values[3];
  time_end = values[4];
  kin_vis = values[5];
  const_den = values[6];
  fclose(fp);
  free(values);
}

int line_count(FILE *fp, char *filename){
  int count_lines = 1;
  char chr;
  while ((chr = getc(fp)) != EOF) {
    if (chr == '\n') {
      count_lines += 1;
    }
    chr = getc(fp);
  }
  count_lines+=1;
  printf("There are %d lines in the file %s\n", count_lines, filename);
  rewind(fp);
  return count_lines;
}
