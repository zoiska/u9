cmake_minimum_required(VERSION 3.26)
project(u9 C)

if(WIN32)
    add_executable(u9 main.c
            circle.c
            circle.h
            rect.c
            rect.h
    )
endif()

if(UNIX)
    # Find ImageMagick
    find_package(ImageMagick REQUIRED COMPONENTS MagickWand)

    # Include ImageMagick headers
    include_directories(${ImageMagick_INCLUDE_DIRS})

    set(CMAKE_C_STANDARD 11)

    set(IMAGE_MAGICK_PATH "C:/Program Files (x86)/ImageMagick-7.1.1-Q8-HDRI")
    set(CMAKE_PREFIX_PATH "${IMAGE_MAGICK_PATH};${CMAKE_PREFIX_PATH}")

    add_executable(u9 main.c
            circle.c
            circle.h
            rect.c
            rect.h
            mandelbrot.c
            mandelbrot.h
    )

    # Link against ImageMagick libraries
    target_compile_definitions(u9 PRIVATE MAGICKCORE_HDRI_ENABLE=1)
    target_compile_definitions(u9 PRIVATE MAGICKCORE_QUANTUM_DEPTH=16)

    target_link_libraries(u9 ${ImageMagick_LIBRARIES})
endif()


# # Specify the location of ImageMagick libraries (modify the path accordingly)
#    link_directories("C:/Program Files (x86)/ImageMagick-7.1.1-Q8-HDRI/lib")
#
#    # Link against the specific ImageMagick libraries
#    target_link_libraries(u9 CORE_RL_MagickCore_.lib)
#    target_link_libraries(u9 CORE_RL_MagickWand_.lib)
#
#    # Copy required DLLs from ImageMagick to the output directory
#    file(GLOB IMAGEMAGICK_DLLS "C:/Program Files (x86)/ImageMagick-7.1.1-Q8-HDRI/*.dll")
#    foreach(DLL ${IMAGEMAGICK_DLLS})
#        add_custom_command(TARGET u9 POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy_if_different
#                ${DLL} $<TARGET_FILE_DIR:u9>)
#    endforeach()