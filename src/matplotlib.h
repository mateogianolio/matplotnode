#ifndef MATPLOTLIB_H
#define MATPLOTLIB_H

#include <node.h>
#include <string>
#include <python2.7/Python.h>

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

		PyObject *empty_tuple;

		static interpreter& get() {
			static interpreter context;
			return context;
		}
	private:
		interpreter() {
			Py_Initialize();

			PyObject *pyplot = PyImport_Import(PyString_FromString("matplotlib.pyplot"));
			if (!pyplot) {
				fprintf(stderr, "Could not import matplotlib.pyplot.\n");
				return;
			}

			PyObject *pylab = PyImport_Import(PyString_FromString("pylab"));
			if (!pylab) {
				fprintf(stderr, "Could not import pylab.\n");
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

			save = PyObject_GetAttrString(pylab, "savefig");

			Py_DECREF(pyplot);
			Py_DECREF(pylab);

			if (!plot ||
				!subplot ||
				!show ||
				!legend ||
				!grid ||
				!save ||
				!xlim ||
				!ylim ||
				!title ||
				!axis ||
				!xlabel ||
				!ylabel) {
				fprintf(stderr, "Error loading matplotlib functions.\n");
				return;
			}

			if (!PyCallable_Check(plot) ||
				!PyCallable_Check(subplot) ||
				!PyCallable_Check(show) ||
				!PyCallable_Check(legend) ||
				!PyCallable_Check(grid) ||
				!PyCallable_Check(save) ||
				!PyCallable_Check(xlim) ||
				!PyCallable_Check(ylim) ||
				!PyCallable_Check(title) ||
				!PyCallable_Check(axis) ||
				!PyCallable_Check(xlabel) ||
				!PyCallable_Check(ylabel)) {
				fprintf(stderr, "One or more of the matplotlib functions are not callable.\n");
				return;
			}

			empty_tuple = PyTuple_New(0);
		}

		~interpreter() {
			Py_DECREF(plot);
			Py_DECREF(subplot);
			Py_DECREF(show);
			Py_DECREF(legend);
			Py_DECREF(grid);
			Py_DECREF(save);
			Py_DECREF(xlim);
			Py_DECREF(ylim);
			Py_DECREF(title);
			Py_DECREF(axis);
			Py_DECREF(xlabel);
			Py_DECREF(ylabel);
			Py_DECREF(empty_tuple);
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
}

#endif