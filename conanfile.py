from conans import ConanFile, CMake

class TestConan(ConanFile):
   settings = "os", "compiler", "build_type", "arch"
   requires = "boost/1.71.0@conan/stable"
   generators = "cmake"
