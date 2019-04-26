#ifndef MATPLOTLIB_H
#define MATPLOTLIB_H

#include <node.h>
#include <string>
#include <Python.h>

#if PY_MAJOR_VERSION >= 3
	#define PyString_FromString PyUnicode_FromString
#endif

#ifndef WITHOUT_NUMPY
#  define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#  include <numpy/arrayobject.h>
#endif // WITHOUT_NUMPY

namespace plt {
	struct interpreter {
	public:
		PyObject *plot;
		PyObject *subplot;
		PyObject *show;
		PyObject *legend;
		PyObject *grid;
		PyObject *save;
		PyObject *xlim;
		PyObject *ylim;
		PyObject *title;
		PyObject *axis;
		PyObject *xlabel;
		PyObject *ylabel;
		PyObject *clf;
		PyObject *cla;
		PyObject *close;
		PyObject *xkcd;

		PyObject *empty_tuple;

		static interpreter& get() {
			static interpreter context;
			return context;
		}
	private:
#ifndef WITHOUT_NUMPY
#  if PY_MAJOR_VERSION >= 3

    void *import_numpy() {
        import_array(); // initialize C-API
        return NULL;
    }

#  else

    void import_numpy() {
        import_array(); // initialize C-API
    }

#  endif
#endif
		interpreter() {
#if PY_MAJOR_VERSION >= 3
			wchar_t name[] = L"matplotnode";
#else
			char name[] = "matplotnode";
#endif
			Py_SetProgramName(name);

#ifdef linux
			dlopen("libpython2.7.so", RTLD_LAZY | RTLD_GLOBAL);
#endif

			Py_Initialize();

#ifndef WITHOUT_NUMPY
        import_numpy(); // initialize numpy C-API
#endif

			PyObject *matplotlibname = PyString_FromString("matplotlib");
			PyObject* matplotlib = PyImport_Import(matplotlibname);
			Py_DECREF(matplotlibname);
			if (!matplotlib) {
				PyErr_Print();
				fprintf(stderr, "Could not import matplotlib.pyplot.\n");
				return;
			}

			PyObject_CallMethod(matplotlib, const_cast<char*>("use"), const_cast<char*>("s"), "TkAgg");

			PyObject *pyplotname = PyString_FromString("matplotlib.pyplot");
			PyObject *pyplot = PyImport_Import(pyplotname);
			Py_DECREF(pyplotname);

			if (!pyplot) {
				PyErr_Print();
				fprintf(stderr, "Could not import matplotlib.pyplot.\n");
				return;
			}

			plot = PyObject_GetAttrString(pyplot, "plot");
			subplot = PyObject_GetAttrString(pyplot, "subplot");
			show = PyObject_GetAttrString(pyplot, "show");
			legend = PyObject_GetAttrString(pyplot, "legend");
			grid = PyObject_GetAttrString(pyplot, "grid");
			save = PyObject_GetAttrString(pyplot, "savefig");
			xlim = PyObject_GetAttrString(pyplot, "xlim");
			ylim = PyObject_GetAttrString(pyplot, "ylim");
			title = PyObject_GetAttrString(pyplot, "title");
			axis = PyObject_GetAttrString(pyplot, "axis");
			xlabel = PyObject_GetAttrString(pyplot, "xlabel");
			ylabel = PyObject_GetAttrString(pyplot, "ylabel");
			clf = PyObject_GetAttrString(pyplot, "clf");
			cla = PyObject_GetAttrString(pyplot, "cla");
			close = PyObject_GetAttrString(pyplot, "close");
			xkcd = PyObject_GetAttrString(pyplot, "xkcd");

			if (!plot
				|| !subplot
				|| !show
				|| !legend
				|| !grid
				|| !save
				|| !xlim
				|| !ylim
				|| !title
				|| !axis
				|| !xlabel
				|| !ylabel
				|| !clf
				|| !cla
				|| !close
				|| !xkcd) {
				PyErr_Print();
				fprintf(stderr, "Error loading matplotlib functions.\n");
				return;
			}

			if (!PyCallable_Check(plot)
				|| !PyCallable_Check(subplot)
				|| !PyCallable_Check(show)
				|| !PyCallable_Check(legend)
				|| !PyCallable_Check(grid)
				|| !PyCallable_Check(save)
				|| !PyCallable_Check(xlim)
				|| !PyCallable_Check(ylim)
				|| !PyCallable_Check(title)
				|| !PyCallable_Check(axis)
				|| !PyCallable_Check(xlabel)
				|| !PyCallable_Check(ylabel)
				|| !PyCallable_Check(clf)
				|| !PyCallable_Check(cla)
				|| !PyCallable_Check(close)
				|| !PyCallable_Check(xkcd)) {
				PyErr_Print();
				fprintf(stderr, "One or more of the matplotlib functions are not callable.\n");
				return;
			}

			empty_tuple = PyTuple_New(0);
		}

		~interpreter() {
			Py_Finalize();
		}
	};

	void plot(v8::FunctionCallbackInfo<v8::Value>& info);
	void subplot(v8::FunctionCallbackInfo<v8::Value>& info);
	void show(v8::FunctionCallbackInfo<v8::Value>& info);
	void legend(v8::FunctionCallbackInfo<v8::Value>& info);
	void grid(v8::FunctionCallbackInfo<v8::Value>& info);
	void save(v8::FunctionCallbackInfo<v8::Value>& info);
	void xlim(v8::FunctionCallbackInfo<v8::Value>& info);
	void ylim(v8::FunctionCallbackInfo<v8::Value>& info);
	void title(v8::FunctionCallbackInfo<v8::Value>& info);
	void axis(v8::FunctionCallbackInfo<v8::Value>& info);
	void xlabel(v8::FunctionCallbackInfo<v8::Value>& info);
	void ylabel(v8::FunctionCallbackInfo<v8::Value>& info);
	void clf(v8::FunctionCallbackInfo<v8::Value>& info);
	void cla(v8::FunctionCallbackInfo<v8::Value>& info);
	void close(v8::FunctionCallbackInfo<v8::Value>& info);
	void xkcd(v8::FunctionCallbackInfo<v8::Value>& info);
}

#endif