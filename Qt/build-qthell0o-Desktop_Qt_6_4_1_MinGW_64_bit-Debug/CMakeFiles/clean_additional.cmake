# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\qthell0o_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\qthell0o_autogen.dir\\ParseCache.txt"
  "qthell0o_autogen"
  )
endif()
