#include <comutil.h>
#pragma comment(lib,"comsuppw.lib")
#include <util.h>

std::string bstr_to_string(LPSTR string_to_convert)
{
	_bstr_t source = _bstr_t(string_to_convert);
	int length = source.length();
	char* char_array = new char[length];
	strcpy_s(char_array, length + 1, source);
	return char_array;
}

BSTR string_to_bstr(std::string string_to_convert)
{
    return _bstr_t(string_to_convert.c_str()).GetBSTR();
}