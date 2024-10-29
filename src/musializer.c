#include <string.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <raylib.h>
#include <visual_plugin.h>
#include <dlfcn.h>

typedef struct VisualPluginFunctions {
  #define VISUAL_PLUGIN(name, ...) name##_t *name;
  LIST_OF_PLUGIN_FUNCTIONS
  #undef VISUAL_PLUGIN
} VisualPluginFunctions;

bool load_plugin(void** libplugin, char* plugin_path, VisualPluginFunctions* visual_plugin_functions){
  if(*libplugin != NULL) dlclose(libplugin);

  // TODO check plugin_path to be valid
  *libplugin = dlopen(plugin_path, RTLD_NOW);
  if (*libplugin == NULL) {
    fprintf(stderr, "ERROR: could not load %s: %s", plugin_path, dlerror());
    return false;
  }

  #define VISUAL_PLUGIN(name, ...) \
    visual_plugin_functions->name = dlsym(*libplugin, #name); \
    if (visual_plugin_functions->name == NULL) { \
      fprintf(stderr, "ERROR: could not find %s symbol in %s: %s", \
        visual_plugin_functions->name, plugin_path, dlerror()); \
      return false; \
    }
    LIST_OF_PLUGIN_FUNCTIONS
  #undef VISUAL_PLUGIN

  return true;
}

int main(int argc, char **argv){
  char* plugin_path;
  void* libplugin = NULL;

  VisualPluginFunctions visual_plugin_functions = {0};

  /* maybe init struct functions with NULL
  #define VISUAL_PLUGIN(name, ...) name##_t *name = NULL;
  LIST_OF_PLUGIN_FUNCTIONS
  #undef PLUG
  */

  InitWindow(800, 600, "Musializer");
  SetTargetFPS(60);
  InitAudioDevice();
  const char *libplugin_file_name = "libplug.so";
  while(!WindowShouldClose()){
    if(IsFileDropped()) {
      FilePathList dropped_files = LoadDroppedFiles();
      if (dropped_files.count > 0) {
        if (dropped_files.count == 1){
          char* file_extension_so = "so";
          if(IsFileExtension(dropped_files.paths[0] , file_extension_so)){
            size_t len = strlen(dropped_files.paths[0]);
            if(plugin_path) {
              free(plugin_path);
            }
            plugin_path = (char*)malloc(len * (sizeof(char)));
            strcpy(plugin_path, dropped_files.paths[0]);
            // TODO: reload plugin
          }
        }
        if(libplugin) {
          visual_plugin_functions.visual_plugin_load_files(libplugin, dropped_files);
        }
      } else {
        UnloadDroppedFiles(dropped_files);    // Unload filepaths from memory
      }
    }
  }
  return 0;
}
