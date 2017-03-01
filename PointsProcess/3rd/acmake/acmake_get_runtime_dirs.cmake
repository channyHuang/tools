include(acmake_get_dll)

function(acmake_get_runtime_dirs OUTPUT)
    acmake_get_dll(DLLS DLLS_DEBUG DLLS_OPTIMIZED ${ARGN})
    set(RESULT)
    foreach(DLL ${DLLS} ${DLLS_DEBUG} ${DLLS_OPTIMIZED})
        get_filename_component(DIR ${DLL} PATH)
        list(APPEND RESULT ${DIR})
    endforeach()
    list(REMOVE_DUPLICATES RESULT)
    set(${OUTPUT} ${RESULT} PARENT_SCOPE)
endfunction()