include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/toolkit
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/asf
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/mpeg
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/ogg
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/ogg/vorbis
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/ogg/flac
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/flac
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/mpc
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/mp4
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/mpeg/id3v2
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/mpeg/id3v2/frames
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/wavpack
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/ogg/speex
  ${CMAKE_CURRENT_SOURCE_DIR}/../../taglib/trueaudio
)

set(tag_c_HDRS tag_c.h)

add_library(tag_c tag_c.cpp ${tag_c_HDRS})

target_link_libraries(tag_c tag)
set_target_properties(tag_c PROPERTIES
  PUBLIC_HEADER "${tag_c_HDRS}"
  DEFINE_SYMBOL MAKE_TAGLIB_LIB
)
if(VISIBILITY_HIDDEN)
	set_target_properties(tag_c PROPERTIES C_VISIBILITY_PRESET hidden
	)
endif()
if(BUILD_FRAMEWORK)
  set_target_properties(tag_c PROPERTIES FRAMEWORK TRUE)
endif()

set_target_properties(tag_c PROPERTIES
  VERSION 0.0.0
  SOVERSION 0
  DEFINE_SYMBOL MAKE_TAGLIB_C_LIB
  INSTALL_NAME_DIR ${CMAKE_INSTALL_FULL_LIBDIR}
)
install(TARGETS tag_c
	FRAMEWORK DESTINATION ${FRAMEWORK_INSTALL_DIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/taglib
)

if(NOT BUILD_FRAMEWORK)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/taglib_c.pc.cmake ${CMAKE_CURRENT_BINARY_DIR}/taglib_c.pc @ONLY)
	install(FILES ${CMAKE_CURRENT_BINARY_DIR}/taglib_c.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
endif()

