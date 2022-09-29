#ifndef BounceBall_INIT_ERROR_HPP
#define BounceBall_INIT_ERROR_HPP
#include "baseException.hpp"
class init_error : public baseException {
public:
	init_error(char const* msg, int code) { data_.what_ = msg; data_.code_ = code; }
	~init_error() = default;

	_NODISCARD char const* what() const override { return data_.what_ ? data_.what_ : "Unknown error"; }
	_NODISCARD int err_code() const { return data_.code_; }
private:
	__exception_data data_;
};

#endif // !BounceBall_INIT_ERROR_HPP