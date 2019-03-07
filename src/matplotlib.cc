#include "matplotlib.h"

namespace plt {
	void plot(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		PyObject *args, *kwargs, *data, *result;
		uint32_t arglen = info.Length();
		uint32_t datalen;

		args = PyTuple_New(2);
		kwargs = PyDict_New();

		for (uint32_t i = 0; i < arglen; i++) {
			if (info[i]->IsString()) {
				std::string s = std::string(*v8::String::Utf8Value(isolate, info[i]->ToString()));

				unsigned long eq = s.find("=");
				if (eq != std::string::npos) {
					std::string left = s.substr(0, eq);
					std::string right = s.substr(eq + 1, s.size() - 1);

					PyDict_SetItemString(kwargs, left.c_str(), PyString_FromString(right.c_str()));
				}
			} else if (info[i]->IsArray()) {
				v8::Local<v8::Array> array = info[i].As<v8::Array>();
				datalen = array->Length();
				data = PyList_New(datalen);

				for (uint32_t j = 0; j < datalen; j++)
					PyList_SetItem(data, j, PyFloat_FromDouble(array->Get(j)->NumberValue()));
				PyTuple_SetItem(args, i, data);
			}
		}

		result = PyObject_Call(interpreter::get().plot, args, kwargs);

		Py_DECREF(args);
		Py_DECREF(kwargs);
		Py_XDECREF(result);
	}

	void subplot(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		std::string s = std::string(*v8::String::Utf8Value(isolate, info[0]->ToString()));
		PyObject *args = PyTuple_New(1);
		PyTuple_SetItem(args, 0, PyString_FromString(s.c_str()));

		PyObject *result = PyObject_CallObject(interpreter::get().subplot, args);

		Py_DECREF(args);
		Py_XDECREF(result);
	}

	void show(const v8::FunctionCallbackInfo<v8::Value>& info) {
		PyObject *result = PyObject_CallObject(interpreter::get().show, interpreter::get().empty_tuple);
		Py_XDECREF(result);
	}

	void legend(const v8::FunctionCallbackInfo<v8::Value>& info) {
		PyObject *result = PyObject_CallObject(interpreter::get().legend, interpreter::get().empty_tuple);
		Py_XDECREF(result);
	}

	void grid(const v8::FunctionCallbackInfo<v8::Value>& info) {
		PyObject *flag = info[0]->BooleanValue() ? Py_True : Py_False;
		PyObject *args = PyTuple_New(1);
		PyTuple_SetItem(args, 0, flag);

		PyObject *result = PyObject_CallObject(interpreter::get().grid, args);
		
		Py_DECREF(args);
		Py_XDECREF(result);
	}

	void save(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		std::string s = std::string(*v8::String::Utf8Value(isolate, info[0]->ToString()));
		PyObject *args = PyTuple_New(1);
		PyTuple_SetItem(args, 0, PyString_FromString(s.c_str()));

		PyObject *result = PyObject_CallObject(interpreter::get().save, args);

		Py_DECREF(args);
		Py_XDECREF(result);
	}

	void xlim(const v8::FunctionCallbackInfo<v8::Value>& info) {
		PyObject *list = PyList_New(2);
		PyObject *args = PyTuple_New(1);

		PyList_SetItem(list, 0, PyFloat_FromDouble(info[0]->NumberValue()));
		PyList_SetItem(list, 1, PyFloat_FromDouble(info[1]->NumberValue()));
		PyTuple_SetItem(args, 0, list);

		PyObject *result = PyObject_CallObject(interpreter::get().xlim, args);

		Py_DECREF(args);
		Py_XDECREF(result);
	}
	
	void ylim(const v8::FunctionCallbackInfo<v8::Value>& info) {
		PyObject *list = PyList_New(2);
		PyObject *args = PyTuple_New(1);

		PyList_SetItem(list, 0, PyFloat_FromDouble(info[0]->NumberValue()));
		PyList_SetItem(list, 1, PyFloat_FromDouble(info[1]->NumberValue()));
		PyTuple_SetItem(args, 0, list);

		PyObject *result = PyObject_CallObject(interpreter::get().ylim, args);
		
		Py_DECREF(args);
		Py_XDECREF(result);
	}

	void title(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		std::string s = std::string(*v8::String::Utf8Value(isolate, info[0]->ToString()));
		PyObject *args = PyTuple_New(1);
		PyTuple_SetItem(args, 0, PyString_FromString(s.c_str()));

		PyObject *result = PyObject_CallObject(interpreter::get().title, args);

		Py_DECREF(args);
		Py_XDECREF(result);
	}

	void axis(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		std::string s = std::string(*v8::String::Utf8Value(isolate, info[0]->ToString()));
		PyObject *args = PyTuple_New(1);
		PyTuple_SetItem(args, 0, PyString_FromString(s.c_str()));

		PyObject *result = PyObject_CallObject(interpreter::get().axis, args);

		Py_DECREF(args);
		Py_XDECREF(result);
	}

	void xlabel(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		std::string s = std::string(*v8::String::Utf8Value(isolate, info[0]->ToString()));
		PyObject *args = PyTuple_New(1);
		PyTuple_SetItem(args, 0, PyString_FromString(s.c_str()));

		PyObject *result = PyObject_CallObject(interpreter::get().xlabel, args);

		Py_DECREF(args);
		Py_XDECREF(result);
	}

	void ylabel(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		std::string s = std::string(*v8::String::Utf8Value(isolate, info[0]->ToString()));
		PyObject *args = PyTuple_New(1);
		PyTuple_SetItem(args, 0, PyString_FromString(s.c_str()));

		PyObject *result = PyObject_CallObject(interpreter::get().ylabel, args);

		Py_DECREF(args);
		Py_XDECREF(result);
	}

	void clf(const v8::FunctionCallbackInfo<v8::Value>& info) {
		PyObject *result = PyObject_CallObject(interpreter::get().clf, interpreter::get().empty_tuple);
		Py_XDECREF(result);
	}

	void cla(const v8::FunctionCallbackInfo<v8::Value>& info) {
		PyObject *result = PyObject_CallObject(interpreter::get().cla, interpreter::get().empty_tuple);
		Py_XDECREF(result);
	}

	void close(const v8::FunctionCallbackInfo<v8::Value>& info) {
		PyObject *result = PyObject_CallObject(interpreter::get().close, interpreter::get().empty_tuple);
		Py_XDECREF(result);
	}

	void xkcd(const v8::FunctionCallbackInfo<v8::Value>& info) {
    PyObject *kwargs = PyDict_New();
    PyObject *result = PyObject_Call(interpreter::get().xkcd, interpreter::get().empty_tuple, kwargs);

    Py_DECREF(kwargs);
    Py_DECREF(result);
	}
}

void init(v8::Local<v8::Object> exports) {
	NODE_SET_METHOD(exports, "plot", plt::plot);
	NODE_SET_METHOD(exports, "subplot", plt::subplot);
	NODE_SET_METHOD(exports, "show", plt::show);
	NODE_SET_METHOD(exports, "legend", plt::legend);
	NODE_SET_METHOD(exports, "grid", plt::grid);
	NODE_SET_METHOD(exports, "save", plt::save);
	NODE_SET_METHOD(exports, "xlim", plt::xlim);
	NODE_SET_METHOD(exports, "ylim", plt::ylim);
	NODE_SET_METHOD(exports, "title", plt::title);
	NODE_SET_METHOD(exports, "axis", plt::axis);
	NODE_SET_METHOD(exports, "xlabel", plt::xlabel);
	NODE_SET_METHOD(exports, "ylabel", plt::ylabel);
	NODE_SET_METHOD(exports, "clf", plt::clf);
	NODE_SET_METHOD(exports, "cla", plt::cla);
	NODE_SET_METHOD(exports, "close", plt::close);
	NODE_SET_METHOD(exports, "xkcd", plt::xkcd);
}

NODE_MODULE(matplotlib, init)