#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <raylib.h>

int main(int argc, char **argv){
  InitWindow(800, 600, "Musializer");
  SetTargetFPS(60);
  InitAudioDevice();
  const char *libplugin_file_name = "libplug.so";
  while(!WindowShouldClose()){
  }
  return 0;
}
