file(REMOVE_RECURSE
  "libfluidsynth.pdb"
  "libfluidsynth.so.2.3.0"
  "libfluidsynth.so"
  "libfluidsynth.so.2"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/libfluidsynth.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
