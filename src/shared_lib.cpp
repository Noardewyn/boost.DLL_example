#include <boost/config.hpp>

#define API extern "C" BOOST_SYMBOL_EXPORT

API int life_answer = 42;

API int add(int a, int b) {
  return a + b;
}
