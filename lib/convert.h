#pragma once

#include <node.h>

template<typename T, typename Enable = void>
struct convert;

// Number => float | double
template<typename T>
struct convert<T, typename std::enable_if<std::is_floating_point<T>::value>::type> {
	static T from(v8::Isolate* isolate, v8::Local<v8::Value> value, T default_value = 0.0) {
		if (value.IsEmpty() || !value->IsNumber()) {
			return default_value;
		}

		return value.As<v8::Number>()->Value();
	}
};

// Number => int32_t | uint32_t | int64_t
template<typename T>
struct convert<T, typename std::enable_if<std::is_integral<T>::value>::type> {
	enum {
		bits = sizeof(T) * CHAR_BIT,
		is_signed = std::is_signed<T>::value
	};

	static T from(v8::Isolate* isolate, v8::Local<v8::Value> value, T default_value = 0) {
		if (value.IsEmpty() || !value->IsNumber()) {
			return default_value;
		}

		printf("bits: %d\n", bits);
		printf("is_signed: %d\n", is_signed);

		if (bits <= 32) {
			if (is_signed) {
				return value.As<v8::Int32>()->Value();
			} else {
				return value.As<v8::Uint32>()->Value();
			}
		}

		return value.As<v8::Integer>()->Value();
	}
};

// Boolean => bool
template<>
struct convert<bool> {
	static bool from(v8::Isolate* isolate, v8::Local<v8::Value> value, bool default_value = false) {
		if (value.IsEmpty() || !value->IsBoolean()) {
			return default_value;
		}

		return value.As<v8::Boolean>()->Value();
	}
};

// String => std::string
template<>
struct convert<std::string> {
	static std::string from(v8::Isolate* isolate, v8::Local<v8::Value> value, std::string default_value = "") {
		if (value.IsEmpty() || !value->IsString()) {
			return default_value;
		}

		return std::string(*v8::String::Utf8Value(isolate, value.As<v8::String>()));
	}
};

// Array<T> => std::vector<T>
template<typename T>
struct convert<std::vector<T>> {
	static std::vector<T> from(v8::Isolate* isolate, v8::Local<v8::Value> value, std::vector<T> default_value = {}) {
		if (value.IsEmpty() || (!value->IsArray() && !value->IsTypedArray())) {
			return default_value;
		}

		v8::HandleScope scope(isolate);
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		v8::Local<v8::Array> array = value.As<v8::Array>();

		std::vector<T> output;

		output.reserve(array->Length());
		for (uint32_t i = 0, count = array->Length(); i < count; ++i) {
			output.emplace_back(convert<T>::from(isolate, array->Get(context, i).ToLocalChecked()));
		}

		return output;
	}
};

// Object<T, U> => std::map<T, U>
template<typename T, typename U>
struct convert<std::map<T, U>> {
	static std::map<T, U> from(v8::Isolate* isolate, v8::Local<v8::Value> value, std::map<T, U> default_value = {}) {
		if (value.IsEmpty() || !value->IsObject()) {
			return default_value;
		}

		v8::HandleScope scope(isolate);
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		v8::Local<v8::Object> object = value.As<v8::Object>();
		v8::Local<v8::Array> keys = object->GetPropertyNames(context).ToLocalChecked();

		std::map<T, U> output;

		for (uint32_t i = 0, count = keys->Length(); i < count; ++i) {
			v8::Local<v8::Value> key = keys->Get(context, i).ToLocalChecked();
			v8::Local<v8::Value> value = object->Get(context, key).ToLocalChecked();

			output.emplace(convert<T>::from(isolate, key), convert<U>::from(isolate, value));
		}

		return output;
	}
};

template<typename T>
auto from(v8::Isolate* isolate, v8::Local<v8::Value> value)
	-> decltype(convert<T>::from(isolate, value)) {
		return convert<T>::from(isolate, value);
}
