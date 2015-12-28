cmake_minimum_required(VERSION 2.8)

# Grive version. remember to update it for every new release!
set( GRIVE_VERSION "0.4.2-pre" )


# common compile options
add_definitions( -DVERSION="${GRIVE_VERSION}" )
add_definitions( -D_FILE_OFFSET_BITS=64 )

add_subdirectory( libgrive )
add_subdirectory( grive )

set( GRIVE_PLATEFORM_LINUX 1 )
set( GRIVE_PLATEFORM_WIN 2 )
set( GRIVE_PLATEFORM_MAC 3 )

set( GRIVE_PLATEFORM GRIVE_PLATEFORM_LINUX )
