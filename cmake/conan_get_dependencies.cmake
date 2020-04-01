macro(conan_get_dependencies _conanfile_path _install_dir)

message(STATUS "\n\n-----> Conan - Installing dependencies...")

execute_process(COMMAND conan install ${_conanfile_path}
                RESULT_VARIABLE return_code				 
                WORKING_DIRECTORY ${_install_dir})

include(${_install_dir}/conanbuildinfo.cmake)
conan_basic_setup()
conan_set_vs_runtime()
conan_set_libcxx()
conan_output_dirs_setup()

message(STATUS "-----> Conan - Installing dependencies - done.\n\n")

endmacro()
