# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\flappybird_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\flappybird_autogen.dir\\ParseCache.txt"
  "flappybird_autogen"
  )
endif()
