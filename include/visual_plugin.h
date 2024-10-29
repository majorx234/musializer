#ifndef VISUAL_PLUGIN_H_
#define VISUAL_PLUGIN_H_

#include <complex.h>
#include <raylib.h>

#define LIST_OF_PLUGIN_FUNCTIONS \
  VISUAL_PLUGIN(visual_plugin_init, void*, void) \
  VISUAL_PLUGIN(visual_plugin_pre_reload, void, void*) \
  VISUAL_PLUGIN(visual_plugin_post_reload, void, void*) \
  VISUAL_PLUGIN(visual_plugin_update, void, void*) \
  VISUAL_PLUGIN(visual_plugin_load_files, void, void*, FilePathList) \
  VISUAL_PLUGIN(visual_plugin_close, void*) \

#define VISUAL_PLUGIN(name, ret, ...) typedef ret (name##_t)(__VA_ARGS__);
LIST_OF_PLUGIN_FUNCTIONS
#undef VISUAL_PLUGIN

#endif // VISUAL_PLUGIN_H_
