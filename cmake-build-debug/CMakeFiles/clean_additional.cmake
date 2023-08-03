# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PdfToWord_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PdfToWord_autogen.dir\\ParseCache.txt"
  "PdfToWord_autogen"
  )
endif()
