#include <node.h>
#include "matplotlibcpp.h"
#include "convert.h"

namespace matplotnode {
	void backend(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = v8::Isolate::GetCurrent();

		auto name = from<std::string>(isolate, info[0]);

		matplotlibcpp::backend(name);
	}

	void annotate(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = v8::Isolate::GetCurrent();

		auto annotation = from<std::string>(isolate, info[0]);
		auto x = from<double>(isolate, info[1]);
		auto y = from<double>(isolate, info[2]);

		matplotlibcpp::annotate(annotation, x, y);
	}

	void plot(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto x = from<std::vector<double>>(isolate, info[0]);
		auto y = from<std::vector<double>>(isolate, info[1]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[2]);

		matplotlibcpp::plot(x, y, keywords);
	}

	void plot3(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto x = from<std::vector<double>>(isolate, info[0]);
		auto y = from<std::vector<double>>(isolate, info[1]);
		auto z = from<std::vector<double>>(isolate, info[2]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[3]);

		matplotlibcpp::plot3(x, y, z, keywords);
	}

	void stem(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto x = from<std::vector<double>>(isolate, info[0]);
		auto y = from<std::vector<double>>(isolate, info[1]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[2]);

		matplotlibcpp::stem(x, y, keywords);
	}

	void fill(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto x = from<std::vector<double>>(isolate, info[0]);
		auto y = from<std::vector<double>>(isolate, info[1]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[2]);

		matplotlibcpp::fill(x, y, keywords);
	}

	void fill_between(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto x = from<std::vector<double>>(isolate, info[0]);
		auto y1 = from<std::vector<double>>(isolate, info[1]);
		auto y2 = from<std::vector<double>>(isolate, info[2]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[3]);

		matplotlibcpp::fill_between(x, y1, y2, keywords);
	}

	void hist(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto y = from<std::vector<double>>(isolate, info[0]);
		auto bins = from<long>(isolate, info[1]);
		auto color = from<std::string>(isolate, info[2]);
		auto alpha = from<double>(isolate, info[3]);
		auto cumulative = from<bool>(isolate, info[4]);

		matplotlibcpp::hist(y, bins, color, alpha, cumulative);
	}

	void scatter(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto x = from<std::vector<double>>(isolate, info[0]);
		auto y = from<std::vector<double>>(isolate, info[1]);
		auto s = from<double>(isolate, info[2]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[3]);

		matplotlibcpp::scatter(x, y, s, keywords);
	}

	void boxplot(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto data = from<std::vector<double>>(isolate, info[0]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[1]);

		matplotlibcpp::boxplot(data, keywords);
	}

	void bar(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto x = from<std::vector<double>>(isolate, info[0]);
		auto y = from<std::vector<double>>(isolate, info[1]);
		auto ec = from<std::string>(isolate, info[2]);
		auto ls = from<std::string>(isolate, info[3]);
		auto lw = from<double>(isolate, info[4]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[5]);

		matplotlibcpp::bar(x, y, ec, ls, lw, keywords);
	}

	void subplots_adjust(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto keywords = convert<std::map<std::string, double>>::from(isolate, info[0]);

		matplotlibcpp::subplots_adjust(keywords);
	}

	void named_hist(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto label = from<std::string>(isolate, info[0]);
		auto y = from<std::vector<double>>(isolate, info[1]);
		auto bins = from<double>(isolate, info[2]);
		auto color = from<std::string>(isolate, info[3]);
		auto alpha = from<double>(isolate, info[4]);

		matplotlibcpp::named_hist(label, y, bins, color, alpha);
	}

	void quiver(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto x = from<std::vector<double>>(isolate, info[0]);
		auto y = from<std::vector<double>>(isolate, info[1]);
		auto u = from<std::vector<double>>(isolate, info[2]);
		auto w = from<std::vector<double>>(isolate, info[3]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[4]);

		matplotlibcpp::quiver(x, y, u, w, keywords);
	}

	void errorbar(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto x = from<std::vector<double>>(isolate, info[0]);
		auto y1 = from<std::vector<double>>(isolate, info[1]);
		auto yerr = from<std::vector<double>>(isolate, info[2]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[3]);

		matplotlibcpp::errorbar(x, y1, yerr, keywords);
	}

	void named_plot(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto name = from<std::string>(isolate, info[0]);
		auto x = from<std::vector<double>>(isolate, info[1]);
		auto y = from<std::vector<double>>(isolate, info[2]);
		auto format = from<std::string>(isolate, info[3]);

		matplotlibcpp::named_plot(name, x, y, format);
	}

	void named_semilogx(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto name = from<std::string>(isolate, info[0]);
		auto x = from<std::vector<double>>(isolate, info[1]);
		auto y = from<std::vector<double>>(isolate, info[2]);
		auto format = from<std::string>(isolate, info[3]);

		matplotlibcpp::named_semilogx(name, x, y, format);
	}

	void named_semilogy(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto name = from<std::string>(isolate, info[0]);
		auto x = from<std::vector<double>>(isolate, info[1]);
		auto y = from<std::vector<double>>(isolate, info[2]);
		auto format = from<std::string>(isolate, info[3]);

		matplotlibcpp::named_semilogy(name, x, y, format);
	}

	void named_loglog(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto name = from<std::string>(isolate, info[0]);
		auto x = from<std::vector<double>>(isolate, info[1]);
		auto y = from<std::vector<double>>(isolate, info[2]);
		auto format = from<std::string>(isolate, info[3]);

		matplotlibcpp::named_loglog(name, x, y, format);
	}

	void text(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = v8::Isolate::GetCurrent();

		auto x = from<double>(isolate, info[0]);
		auto y = from<double>(isolate, info[1]);
		auto s = from<std::string>(isolate, info[2]);

		matplotlibcpp::text(x, y, s);
	}

	void figure(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto number = from<long>(isolate, info[0]);

		matplotlibcpp::figure(number);
	}

	void figure_size(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto w = convert<size_t>::from(isolate, info[0]);
		auto h = convert<size_t>::from(isolate, info[1]);

		matplotlibcpp::figure_size(w, h);
	}

	void legend(const v8::FunctionCallbackInfo<v8::Value>& info) {
		matplotlibcpp::legend();
	}

	void ylim(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto left = from<double>(isolate, info[0]);
		auto right = from<double>(isolate, info[1]);

		matplotlibcpp::ylim(left, right);
	}

	void xlim(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto left = from<double>(isolate, info[0]);
		auto right = from<double>(isolate, info[1]);

		matplotlibcpp::xlim(left, right);
	}

	void xticks(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto ticks = from<std::vector<double>>(isolate, info[0]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[1]);

		matplotlibcpp::xticks(ticks, keywords);
	}

	void yticks(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto ticks = from<std::vector<double>>(isolate, info[0]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[1]);

		matplotlibcpp::yticks(ticks, keywords);
	}

	void tick_params(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto keywords = from<std::map<std::string, std::string>>(isolate, info[0]);
		auto axis = from<std::string>(isolate, info[1]);

		matplotlibcpp::tick_params(keywords, axis);
	}

	void subplot(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto nrows = from<long>(isolate, info[0]);
		auto ncols = from<long>(isolate, info[1]);
		auto plot_number = from<long>(isolate, info[2]);

		matplotlibcpp::subplot(nrows, ncols, plot_number);
	}

	void subplot2grid(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto nrows = from<long>(isolate, info[0]);
		auto ncols = from<long>(isolate, info[1]);
		auto rowid = from<long>(isolate, info[2]);
		auto colid = from<long>(isolate, info[3]);
		auto rowspan = from<long>(isolate, info[4]);
		auto colspan = from<long>(isolate, info[5]);

		matplotlibcpp::subplot2grid(nrows, ncols, rowid, colid, rowspan, colspan);
	}

	void title(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto titlestr = from<std::string>(isolate, info[0]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[1]);

		matplotlibcpp::title(titlestr, keywords);
	}

	void suptitle(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto suptitlestr = from<std::string>(isolate, info[0]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[1]);

		matplotlibcpp::suptitle(suptitlestr, keywords);
	}

	void axis(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto axisstr = from<std::string>(isolate, info[0]);

		matplotlibcpp::axis(axisstr);
	}

	void axvline(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto x = from<double>(isolate, info[0]);
		auto ymin = from<double>(isolate, info[1]);
		auto ymax = from<double>(isolate, info[2]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[3]);

		matplotlibcpp::axvline(x, ymin, ymax, keywords);
	}

	void xlabel(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto str = from<std::string>(isolate, info[0]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[1]);

		matplotlibcpp::xlabel(str, keywords);
	}

	void ylabel(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto str = from<std::string>(isolate, info[0]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[1]);

		matplotlibcpp::ylabel(str, keywords);
	}

	void set_zlabel(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto str = from<std::string>(isolate, info[0]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[1]);

		matplotlibcpp::set_zlabel(str, keywords);
	}

	void grid(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto flag = from<bool>(isolate, info[0]);

		matplotlibcpp::grid(flag);
	}

	void show(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto block = from<bool>(isolate, info[0]);

		matplotlibcpp::show(block);
	}

	void close(const v8::FunctionCallbackInfo<v8::Value>& info) {
		matplotlibcpp::close();
	}

	void xkcd(const v8::FunctionCallbackInfo<v8::Value>& info) {
		matplotlibcpp::xkcd();
	}

	void draw(const v8::FunctionCallbackInfo<v8::Value>& info) {
		matplotlibcpp::draw();
	}

	void pause(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto interval = from<double>(isolate, info[0]);

		matplotlibcpp::pause(interval);
	}

	void save(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto filename = from<std::string>(isolate, info[0]);

		matplotlibcpp::save(filename);
	}

	void clf(const v8::FunctionCallbackInfo<v8::Value>& info) {
		matplotlibcpp::clf();
	}

	void ion(const v8::FunctionCallbackInfo<v8::Value>& info) {
		matplotlibcpp::ion();
	}

	void ginput(const v8::FunctionCallbackInfo<v8::Value>& info) {
		v8::Isolate* isolate = info.GetIsolate();

		auto numClicks = from<int>(isolate, info[0]);
		auto keywords = from<std::map<std::string, std::string>>(isolate, info[1]);

		matplotlibcpp::ginput(numClicks, keywords);
	}

	void tight_layout(const v8::FunctionCallbackInfo<v8::Value>& info) {
		matplotlibcpp::tight_layout();
	}
}

void init(v8::Local<v8::Object> exports) {
	NODE_SET_METHOD(exports, "backend", matplotnode::backend);
	NODE_SET_METHOD(exports, "annotate", matplotnode::annotate);
	NODE_SET_METHOD(exports, "plot", matplotnode::plot);
	NODE_SET_METHOD(exports, "plot3", matplotnode::plot3);
	NODE_SET_METHOD(exports, "stem", matplotnode::stem);
	NODE_SET_METHOD(exports, "fill", matplotnode::fill);
	NODE_SET_METHOD(exports, "fill_between", matplotnode::fill_between);
	NODE_SET_METHOD(exports, "hist", matplotnode::hist);
	NODE_SET_METHOD(exports, "scatter", matplotnode::scatter);
	NODE_SET_METHOD(exports, "boxplot", matplotnode::boxplot);
	NODE_SET_METHOD(exports, "bar", matplotnode::bar);
	NODE_SET_METHOD(exports, "subplots_adjust", matplotnode::subplots_adjust);
	NODE_SET_METHOD(exports, "named_hist", matplotnode::named_hist);
	NODE_SET_METHOD(exports, "quiver", matplotnode::quiver);
	NODE_SET_METHOD(exports, "errorbar", matplotnode::errorbar);
	NODE_SET_METHOD(exports, "named_plot", matplotnode::named_plot);
	NODE_SET_METHOD(exports, "named_semilogx", matplotnode::named_semilogx);
	NODE_SET_METHOD(exports, "named_semilogy", matplotnode::named_semilogy);
	NODE_SET_METHOD(exports, "named_loglog", matplotnode::named_loglog);
	NODE_SET_METHOD(exports, "text", matplotnode::text);
	NODE_SET_METHOD(exports, "figure", matplotnode::figure);
	NODE_SET_METHOD(exports, "figure_size", matplotnode::figure_size);
	NODE_SET_METHOD(exports, "legend", matplotnode::legend);
	NODE_SET_METHOD(exports, "ylim", matplotnode::ylim);
	NODE_SET_METHOD(exports, "xlim", matplotnode::xlim);
	NODE_SET_METHOD(exports, "xticks", matplotnode::xticks);
	NODE_SET_METHOD(exports, "yticks", matplotnode::yticks);
	NODE_SET_METHOD(exports, "tick_params", matplotnode::tick_params);
	NODE_SET_METHOD(exports, "subplot", matplotnode::subplot);
	NODE_SET_METHOD(exports, "subplot2grid", matplotnode::subplot2grid);
	NODE_SET_METHOD(exports, "title", matplotnode::title);
	NODE_SET_METHOD(exports, "suptitle", matplotnode::suptitle);
	NODE_SET_METHOD(exports, "axis", matplotnode::axis);
	NODE_SET_METHOD(exports, "axvline", matplotnode::axvline);
	NODE_SET_METHOD(exports, "xlabel", matplotnode::xlabel);
	NODE_SET_METHOD(exports, "ylabel", matplotnode::ylabel);
	NODE_SET_METHOD(exports, "set_zlabel", matplotnode::set_zlabel);
	NODE_SET_METHOD(exports, "grid", matplotnode::grid);
	NODE_SET_METHOD(exports, "show", matplotnode::show);
	NODE_SET_METHOD(exports, "close", matplotnode::close);
	NODE_SET_METHOD(exports, "xkcd", matplotnode::xkcd);
	NODE_SET_METHOD(exports, "draw", matplotnode::draw);
	NODE_SET_METHOD(exports, "pause", matplotnode::pause);
	NODE_SET_METHOD(exports, "save", matplotnode::save);
	NODE_SET_METHOD(exports, "clf", matplotnode::clf);
	NODE_SET_METHOD(exports, "ion", matplotnode::ion);
	NODE_SET_METHOD(exports, "ginput", matplotnode::ginput);
	NODE_SET_METHOD(exports, "tight_layout", matplotnode::tight_layout);
}

NODE_MODULE(matplotlib, init)