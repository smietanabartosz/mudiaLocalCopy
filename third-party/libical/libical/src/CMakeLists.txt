add_subdirectory(libical)

if(LIBICAL_BUILD_LIBICALSS)
  add_subdirectory(libicalss)
endif()

if(LIBICAL_BUILD_LIBICALVCAL)
  add_subdirectory(libicalvcal)
endif()

if(ICAL_GLIB)
  add_subdirectory(libical-glib)
endif()

if(LIBICAL_BUILD_TESTING)
  add_subdirectory(test)
endif()
