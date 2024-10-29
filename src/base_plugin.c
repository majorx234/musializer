#include "visual_plugin.h"
#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>

typedef struct BasePlugin {
  bool started;
} BasePlugin;

void* visual_plugin_init(void) {
  BasePlugin* plugin = malloc(sizeof(BasePlugin));
  plugin->started = false;
  return plugin;
}

void visual_plugin_pre_reload(void* plugin) {}

void visual_plugin_post_reload(void* plugin){}

void visual_plugin_update(void *plugin) {}

void visual_plugin_load_files(FilePathList file_path_list) {}

void visual_plugin_close(void* plugin) {
  free(plugin);
}
