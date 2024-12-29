#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct WAVFILE {
  FILE *fptr;

  char riff[4];
  int file_size;
  char file_type_header[4];
  char fmt[4];
  int fmt_len;
  short audioformat;
  short channels;
  int sample_rate;
  int data_size;
  short byte_rate;
  short bits_per_sample;
  char data_header[4];

  int *data;
} WAVFILE;

WAVFILE *open_wav(char *filename) {
  WAVFILE *new_wave = (WAVFILE *)malloc(1 * sizeof(WAVFILE));
  new_wave->fptr = fopen(filename, "r");

  fread(new_wave->riff, 4, 1, new_wave->fptr);
  fread(&new_wave->file_size, 4, 1, new_wave->fptr);
  fread(new_wave->file_type_header, 4, 1, new_wave->fptr);
  fread(new_wave->fmt, 4, 1, new_wave->fptr);
  fread(&new_wave->fmt_len, 4, 1, new_wave->fptr);
  fread(&new_wave->audioformat, 2, 1, new_wave->fptr);
  fread(&new_wave->channels, 2, 1, new_wave->fptr);
  fread(&new_wave->sample_rate, 4, 1, new_wave->fptr);
  fread(&new_wave->data_size, 4, 1, new_wave->fptr);
  fread(&new_wave->byte_rate, 2, 1, new_wave->fptr);
  fread(&new_wave->bits_per_sample, 2, 1, new_wave->fptr);
  fread(new_wave->data_header, 4, 1, new_wave->fptr);

  // get data now that wav header is retrieved
  int data[new_wave->data_size];
  fread(data, 4, new_wave->data_size, new_wave->fptr);
  fclose(new_wave->fptr);

  new_wave->data = &data[0];

  return new_wave;
}
