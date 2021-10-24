# CMake file for DISTRHO Plugins #
# ------------------------------ #

dpf_add_plugin(d_halfinverter
  TARGETS ladspa lv2 vst2
  FILES_DSP
      halfinverter.cpp)

target_include_directories(
  d_halfinverter PUBLIC ".")
