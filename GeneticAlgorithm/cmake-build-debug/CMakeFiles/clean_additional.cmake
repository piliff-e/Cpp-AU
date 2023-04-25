# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/GeneticAlgorithm_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/GeneticAlgorithm_autogen.dir/ParseCache.txt"
  "GeneticAlgorithm_autogen"
  )
endif()
