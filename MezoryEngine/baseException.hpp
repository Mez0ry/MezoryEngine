#ifndef BaseException_HPP
#define BaseException_HPP
#include <exception>
#include <iostream>

struct __exception_data {
	__exception_data() = default;
	__exception_data(const char* str, int code) : what_(str), code_(code){}
	const char* what_;
	int code_;
 };

class baseException : public std::exception
{
public:
	baseException() : data_("",0) { }
	baseException(char const* str, int code) { data_.what_ = str; data_.code_ = code; }
	~baseException() = default;

	_NODISCARD  char const* what() const override { return data_.what_ ? data_.what_ : "Unknown exception"; }
private:
	__exception_data data_;
};

#endif // !BounceBall_BaseException_HPP