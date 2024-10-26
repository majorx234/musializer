#include <stddef.h>
#include <stdio.h>
#include <math.h>

#define STREAM_BUFFER_SIZE 1024
#define PI 3.14159265358979323846


void updateSignal1(float* signal, float frequency, float sample_duration) {
   for (size_t t = 0; t < STREAM_BUFFER_SIZE; ++t) {
        signal[t] = sinf(2*PI * frequency * sample_duration * (float)t);
      }
}


void updateSignal2(float* signal, float frequency, float sample_duration) {
   for (size_t t = 0; t < STREAM_BUFFER_SIZE; ++t) {
        signal[t] = sinf(2*PI * frequency * (float)t/STREAM_BUFFER_SIZE);
      }
}


void main(void){
  float signal1[1024] = {0};
  float signal2[1024] = {0};

  printf("==== compar 2 functions ==== \n\n");
  updateSignal1(signal1,100,1.0/STREAM_BUFFER_SIZE);
  updateSignal2(signal2,100,1.0/STREAM_BUFFER_SIZE);

  for ( int i = 0;i<64;i++){
    printf("normal: sig1[%d] %.3f,    sig2[%d]: %.3f\n",i, signal1[i],i, signal2[i]);
  }

  printf("\n\n");
  printf("==== compar 2 functions with (int/int vs float/int) ==== \n\n");

  updateSignal1(signal1,100,48000/STREAM_BUFFER_SIZE);
  updateSignal2(signal2,100,48000.0/STREAM_BUFFER_SIZE);

  for ( int i = 0;i<64;i++){
    printf("int/int vs Float/int: sig1[%d] %.3f,    sig2[%d]: %.3f\n",i, signal1[i],i, signal2[i]);
  }

}
