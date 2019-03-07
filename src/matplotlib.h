#ifndef MATPLOTLIB_H
#define MATPLOTLIB_H

#include <node.h>
#include <string>
#include <Python.h>

#if PY_MAJOR_VERSION >= 3
	#define PyString_FromString PyUnicode_FromString
#endif

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

		PyObject *empty_tuple;

		static interpreter& get() {
			static interpreter context;
			return context;
		}
	private:
		interpreter() {
#if PY_MAJOR_VERSION >= 3
			wchar_t name[] = L"matplotnode";
#else
			char name[] = "matplotnode";
#endif
			Py_SetProgramName(name);
			Py_Initialize();

			PyObject *pyplotname = PyString_FromString("matplotlib.pyplot");
			PyObject *pyplot = PyImport_Import(pyplotname);

			Py_DECREF(pyplotname);

			if (!pyplot) {
				fprintf(stderr, "Could not import matplotlib.pyplot.\n");
				return;
			}

			plot = PyObject_GetAttrString(pyplot, "plot");
			subplot = PyObject_GetAttrString(pyplot, "subplot");
			show = PyObject_GetAttrString(pyplot, "show");
			legend = PyObject_GetAttrString(pyplot, "legend");
			grid = PyObject_GetAttrString(pyplot, "grid");
			xlim = PyObject_GetAttrString(pyplot, "xlim");
			ylim = PyObject_GetAttrString(pyplot, "ylim");
			title = PyObject_GetAttrString(pyplot, "title");
			axis = PyObject_GetAttrString(pyplot, "axis");
			xlabel = PyObject_GetAttrString(pyplot, "xlabel");
			ylabel = PyObject_GetAttrString(pyplot, "ylabel");
			clf = PyObject_GetAttrString(pyplot, "clf");
			cla = PyObject_GetAttrString(pyplot, "cla");
			close = PyObject_GetAttrString(pyplot, "close");
			save = PyObject_GetAttrString(pyplot, "savefig");

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
				|| !close) {
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
				|| !PyCallable_Check(close)) {
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
}

#endif