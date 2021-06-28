#include <comutil.h>
#pragma comment(lib,"comsuppw.lib")
#include <util.h>

std::string bstr_to_string(BSTR string_to_convert)
{
	auto bstr = _com_util::ConvertBSTRToString(string_to_convert);
	std::string str(bstr);
	delete[] bstr;
	return str;
}

BSTR string_to_bstr(std::string string_to_convert) {
	return _bstr_t(string_to_convert.c_str()).GetBSTR();
}