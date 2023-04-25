# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Genetic_Qt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Genetic_Qt_autogen.dir/ParseCache.txt"
  "Genetic_Qt_autogen"
  )
endif()
