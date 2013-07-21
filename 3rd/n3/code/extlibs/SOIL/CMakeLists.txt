cmake_minimum_required(VERSION 2.8)

project(SOIL)

set(SOIL_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/image_DXT.c
  ${CMAKE_CURRENT_SOURCE_DIR}/image_DXT.h
  ${CMAKE_CURRENT_SOURCE_DIR}/image_helper.c
  ${CMAKE_CURRENT_SOURCE_DIR}/image_helper.h
  ${CMAKE_CURRENT_SOURCE_DIR}/SOIL.c
  ${CMAKE_CURRENT_SOURCE_DIR}/SOIL.h
  ${CMAKE_CURRENT_SOURCE_DIR}/stb_image_aug.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stb_image_aug.h
  ${CMAKE_CURRENT_SOURCE_DIR}/stbi_DDS_aug_c.h
  ${CMAKE_CURRENT_SOURCE_DIR}/stbi_DDS_aug.h
)

add_library(SOIL STATIC ${SOIL_SRCS})
set_target_properties(SOIL PROPERTIES FOLDER extlibs)