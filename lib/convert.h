#pragma once

#include <napi.h>

template<typename T, typename Enable = void>
struct convert {
	static bool valid(Napi::Value value);
	static T from(Napi::Value value);
};

// String => std::string
template<>
struct convert<std::string> {
	static bool valid(Napi::Value value) {
		return !value.IsEmpty() && value.IsString();
	}

	static std::string from(Napi::Value value) {
		if (!valid(value)) {
			throw std::invalid_argument("expected String, got something else");
		}

		return std::string(value.As<Napi::String>());
	}
};

// Number => float | double
template<typename T>
struct convert<T, typename std::enable_if<std::is_floating_point<T>::value>::type> {
	static bool valid(Napi::Value value) {
		return !value.IsEmpty() && value.IsNumber();
	}

	static T from(Napi::Value value) {
		if (!valid(value)) {
			throw std::invalid_argument("floating point conversion expected Number, got something else");
		}

		return value.As<Napi::Number>();
	}
};

// Number => int32_t | uint32_t | int64_t
template<typename T>
struct convert<T, typename std::enable_if<std::is_integral<T>::value>::type> {
	static bool valid(Napi::Value value) {
		return !value.IsEmpty() && value.IsNumber();
	}

	static T from(Napi::Value value) {
		if (!valid(value)) {
			throw std::invalid_argument("integer conversion expected Number, got something else");
		}

		size_t bits = sizeof(T) * CHAR_BIT;
		bool is_signed = std::is_signed<T>::value;

		if (bits <= 32) {
			if (is_signed) {
				return value.As<Napi::Number>().Int32Value();
			} else {
				return value.As<Napi::Number>().Uint32Value();
			}
		}

		return value.As<Napi::Number>().Int64Value();
	}
};

// Boolean => bool
template<>
struct convert<bool> {
	static bool valid(Napi::Value value) {
		return !value.IsEmpty() && value.IsBoolean();
	}

	static bool from(Napi::Value value) {
		if (!valid(value)) {
			throw std::invalid_argument("expected Boolean, got something else");
		}

		return value.As<Napi::Boolean>();
	}
};

// Array<T> => std::vector<T>
template<typename T>
struct convert<std::vector<T>> {
	static bool valid(Napi::Value value) {
		return !value.IsEmpty() && value.IsArray();
	}

	static std::vector<T> from(Napi::Value value) {
		if (!valid(value)) {
			throw std::invalid_argument("expected Array, got something else");
		}

		Napi::Array array = value.As<Napi::Array>();
		std::vector<T> output;

		for (uint32_t i = 0, count = array.Length(); i < count; ++i) {
			output.emplace_back(convert<T>::from(array[i]));
		}

		return output;
	}
};

// Object<T, U> => std::map<T, U>
template<typename T, typename U>
struct convert<std::map<T, U>> {
	static bool valid(Napi::Value value) {
		return !value.IsEmpty() && value.IsObject();
	}

	static std::map<T, U> from(Napi::Value value) {
		if (!valid(value)) {
			throw std::invalid_argument("expected Object, got something else");
		}

		Napi::Object object = value.As<Napi::Object>();
		Napi::Array keys = object.GetPropertyNames();
		std::map<T, U> output;

		for (uint32_t i = 0, count = keys.Length(); i < count; ++i) {
			Napi::Value key = keys[i];
			Napi::Value value = object.Get(key);

			output.emplace(convert<T>::from(key), convert<U>::from(value));
		}

		return output;
	}
};

template<typename T>
auto from(Napi::Value value)
	-> decltype(convert<T>::from(value)) {
		return convert<T>::from(value);
}

template<typename T>
auto from(Napi::Value value, T default_value)
	-> decltype(convert<T>::from(value)) {
		return convert<T>::valid(value)
			? convert<T>::from(value)
			: default_value;
}
