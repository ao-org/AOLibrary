#ifndef UTIL_H
#define UTIL_H

#include <comdef.h>
#include <string>

std::string bstr_to_string(BSTR string_to_convert);
BSTR string_to_bstr(std::string string_to_convert);

#endif