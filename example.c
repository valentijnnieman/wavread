#include "wavread.h"

int main() {
  WAVFILE *wav = open_wav("piano-a-note.wav");

  // wav header
  for (size_t i = 0; i < 4; i++) {
    printf("%c", wav->riff[i]);
  }
  printf("\nfile size: %i\n", wav->file_size);

  for (size_t i = 0; i < 4; i++) {
    printf("%c", wav->file_type_header[i]);
  }
  printf("\n");

  for (size_t i = 0; i < 4; i++) {
    printf("%c", wav->fmt[i]);
  }

  printf("\nfmt size: %i", wav->fmt_len);
  printf("\naudioformat (1 is pcm): %i", wav->audioformat);
  printf("\nnumber of channels: %i", wav->channels);
  printf("\nsample rate: %i", wav->sample_rate);
  printf("\ndata size: %i", wav->data_size);
  printf("\nbyte rate: %i", wav->byte_rate);
  printf("\nbits per sample: %i\n", wav->bits_per_sample);

  for (size_t i = 0; i < 4; i++) {
    printf("%c", wav->data_header[i]);
  }

  // wav data
  for (size_t i = 0; i < wav->data_size; i++) {
    printf("%i, ", wav->data[i]);
  }

  free(wav);
}
