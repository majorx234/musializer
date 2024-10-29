#include "visual_plugin.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct SpectrumPlugin {
  bool started;
} SpectrumPlugin;

void* visual_plugin_init(void) {
  SpectrumPlugin* plugin = malloc(sizeof(SpectrumPlugin));
  plugin->started = false;
  return plugin;
}

void visual_plugin_pre_reload(void* plugin) {}

void visual_plugin_post_reload(void* plugin){}

void visual_plugin_update(void *plugin) {}

void visual_plugin_load_files(void *plugin, FilePathList file_path_list) {
}

void visual_plugin_close(void* plugin) {
  free(plugin);
}
