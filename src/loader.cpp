#include <iostream>
#include "boost/dll/import.hpp"

int main()
{
#ifdef _WIN32
  const boost::filesystem::path plugin_path = "./shared_lib.dll";
#else
  const boost::filesystem::path plugin_path = "./shared_lib.so";
#endif

  const boost::dll::shared_library lib(plugin_path);

  const auto add_func = lib.get<int(int, int)>("add");
  std::cout << "2 + 2 = " << add_func(2, 3) << std::endl;

  const int life_answer = lib.get<const int>("life_answer");
  std::cout << "life_answer: " << life_answer << std::endl;

  return 0;
}
