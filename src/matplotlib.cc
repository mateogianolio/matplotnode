#include <napi.h>
#include "matplotlibcpp.h"
#include "convert.h"

namespace plt = matplotlibcpp;

namespace matplotnode {
	void backend(const Napi::CallbackInfo& info) {
		auto name = from<std::string>(info[0], "");

		plt::backend(name);
	}

	void annotate(const Napi::CallbackInfo& info) {
		auto annotation = from<std::string>(info[0], "");
		auto x = from<double>(info[1], {});
		auto y = from<double>(info[2], {});

		plt::annotate(annotation, x, y);
	}

	void plot(const Napi::CallbackInfo& info) {
		auto x = from<std::vector<double>>(info[0], {});
		auto y = from<std::vector<double>>(info[1], {});
		auto keywords = from<std::map<std::string, std::string>>(info[2], {});

		plt::plot(x, y, keywords);
	}

	void plot3(const Napi::CallbackInfo& info) {
		auto x = from<std::vector<double>>(info[0], {});
		auto y = from<std::vector<double>>(info[1], {});
		auto z = from<std::vector<double>>(info[2], {});
		auto keywords = from<std::map<std::string, std::string>>(info[3], {});

		plt::plot3(x, y, z, keywords);
	}

	void stem(const Napi::CallbackInfo& info) {
		auto x = from<std::vector<double>>(info[0], {});
		auto y = from<std::vector<double>>(info[1], {});
		auto keywords = from<std::map<std::string, std::string>>(info[2], {});

		plt::stem(x, y, keywords);
	}

	void fill(const Napi::CallbackInfo& info) {
		auto x = from<std::vector<double>>(info[0], {});
		auto y = from<std::vector<double>>(info[1], {});
		auto keywords = from<std::map<std::string, std::string>>(info[2], {});

		plt::fill(x, y, keywords);
	}

	void fill_between(const Napi::CallbackInfo& info) {
		auto x = from<std::vector<double>>(info[0], {});
		auto y1 = from<std::vector<double>>(info[1], {});
		auto y2 = from<std::vector<double>>(info[2], {});
		auto keywords = from<std::map<std::string, std::string>>(info[3], {});

		plt::fill_between(x, y1, y2, keywords);
	}

	void hist(const Napi::CallbackInfo& info) {
		auto y = from<std::vector<double>>(info[0], {});
		auto bins = from<long>(info[1], 10);
		auto color = from<std::string>(info[2], "b");
		auto alpha = from<double>(info[3], 1.0);
		auto cumulative = from<bool>(info[4], false);

		plt::hist(y, bins, color, alpha, cumulative);
	}

	void scatter(const Napi::CallbackInfo& info) {
		auto x = from<std::vector<double>>(info[0], {});
		auto y = from<std::vector<double>>(info[1], {});
		auto s = from<double>(info[2], 1.0);
		auto keywords = from<std::map<std::string, std::string>>(info[3], {});

		plt::scatter(x, y, s, keywords);
	}

	void boxplot(const Napi::CallbackInfo& info) {
		auto data = from<std::vector<double>>(info[0], {});
		auto keywords = from<std::map<std::string, std::string>>(info[1], {});

		plt::boxplot(data, keywords);
	}

	void bar(const Napi::CallbackInfo& info) {
		auto x = from<std::vector<double>>(info[0], {});
		auto y = from<std::vector<double>>(info[1], {});
		auto ec = from<std::string>(info[2], "black");
		auto ls = from<std::string>(info[3], "-");
		auto lw = from<double>(info[4], 1.0);
		auto keywords = from<std::map<std::string, std::string>>(info[5], {});

		plt::bar(x, y, ec, ls, lw, keywords);
	}

	void subplots_adjust(const Napi::CallbackInfo& info) {
		auto keywords = from<std::map<std::string, double>>(info[0], {});

		plt::subplots_adjust(keywords);
	}

	void named_hist(const Napi::CallbackInfo& info) {
		auto label = from<std::string>(info[0], "");
		auto y = from<std::vector<double>>(info[1], {});
		auto bins = from<double>(info[2], 10);
		auto color = from<std::string>(info[3], "b");
		auto alpha = from<double>(info[4], 1.0);

		plt::named_hist(label, y, bins, color, alpha);
	}

	void quiver(const Napi::CallbackInfo& info) {
		auto x = from<std::vector<double>>(info[0], {});
		auto y = from<std::vector<double>>(info[1], {});
		auto u = from<std::vector<double>>(info[2], {});
		auto w = from<std::vector<double>>(info[3], {});
		auto keywords = from<std::map<std::string, std::string>>(info[4], {});

		plt::quiver(x, y, u, w, keywords);
	}

	void errorbar(const Napi::CallbackInfo& info) {
		auto x = from<std::vector<double>>(info[0], {});
		auto y1 = from<std::vector<double>>(info[1], {});
		auto yerr = from<std::vector<double>>(info[2], {});
		auto keywords = from<std::map<std::string, std::string>>(info[3], {});

		plt::errorbar(x, y1, yerr, keywords);
	}

	void named_plot(const Napi::CallbackInfo& info) {
		auto name = from<std::string>(info[0], "");
		auto x = from<std::vector<double>>(info[1], {});
		auto y = from<std::vector<double>>(info[2], {});
		auto format = from<std::string>(info[3], "");

		plt::named_plot(name, x, y, format);
	}

	void named_semilogx(const Napi::CallbackInfo& info) {
		auto name = from<std::string>(info[0], "");
		auto x = from<std::vector<double>>(info[1], {});
		auto y = from<std::vector<double>>(info[2], {});
		auto format = from<std::string>(info[3], "");

		plt::named_semilogx(name, x, y, format);
	}

	void named_semilogy(const Napi::CallbackInfo& info) {
		auto name = from<std::string>(info[0], "");
		auto x = from<std::vector<double>>(info[1], {});
		auto y = from<std::vector<double>>(info[2], {});
		auto format = from<std::string>(info[3], "");

		plt::named_semilogy(name, x, y, format);
	}

	void named_loglog(const Napi::CallbackInfo& info) {
		auto name = from<std::string>(info[0], "");
		auto x = from<std::vector<double>>(info[1], {});
		auto y = from<std::vector<double>>(info[2], {});
		auto format = from<std::string>(info[3], "");

		plt::named_loglog(name, x, y, format);
	}

	void text(const Napi::CallbackInfo& info) {
		auto x = from<double>(info[0], {});
		auto y = from<double>(info[1], {});
		auto s = from<std::string>(info[2], "");

		plt::text(x, y, s);
	}

	void figure(const Napi::CallbackInfo& info) {
		auto number = from<long>(info[0], 0);

		plt::figure(number);
	}

	void figure_size(const Napi::CallbackInfo& info) {
		auto w = from<size_t>(info[0], 0);
		auto h = from<size_t>(info[1], 0);

		plt::figure_size(w, h);
	}

	void legend(const Napi::CallbackInfo& info) {
		plt::legend();
	}

	void ylim(const Napi::CallbackInfo& info) {
		auto left = from<double>(info[0], 0.0);
		auto right = from<double>(info[1], 0.0);

		plt::ylim(left, right);
	}

	void xlim(const Napi::CallbackInfo& info) {
		auto left = from<double>(info[0], 0.0);
		auto right = from<double>(info[1], 0.0);

		plt::xlim(left, right);
	}

	void xticks(const Napi::CallbackInfo& info) {
		auto ticks = from<std::vector<double>>(info[0], {});
		auto keywords = from<std::map<std::string, std::string>>(info[1], {});

		plt::xticks(ticks, keywords);
	}

	void yticks(const Napi::CallbackInfo& info) {
		auto ticks = from<std::vector<double>>(info[0], {});
		auto keywords = from<std::map<std::string, std::string>>(info[1], {});

		plt::yticks(ticks, keywords);
	}

	void tick_params(const Napi::CallbackInfo& info) {
		auto keywords = from<std::map<std::string, std::string>>(info[0], {});
		auto axis = from<std::string>(info[1], "");

		plt::tick_params(keywords, axis);
	}

	void subplot(const Napi::CallbackInfo& info) {
		auto nrows = from<long>(info[0], 0);
		auto ncols = from<long>(info[1], 0);
		auto plot_number = from<long>(info[2], 0);

		plt::subplot(nrows, ncols, plot_number);
	}

	void subplot2grid(const Napi::CallbackInfo& info) {
		auto nrows = from<long>(info[0], 0);
		auto ncols = from<long>(info[1], 0);
		auto rowid = from<long>(info[2], 0);
		auto colid = from<long>(info[3], 0);
		auto rowspan = from<long>(info[4], 0);
		auto colspan = from<long>(info[5], 0);

		plt::subplot2grid(nrows, ncols, rowid, colid, rowspan, colspan);
	}

	void title(const Napi::CallbackInfo& info) {
		auto titlestr = from<std::string>(info[0], "");
		auto keywords = from<std::map<std::string, std::string>>(info[1], {});

		plt::title(titlestr, keywords);
	}

	void suptitle(const Napi::CallbackInfo& info) {
		auto suptitlestr = from<std::string>(info[0], "");
		auto keywords = from<std::map<std::string, std::string>>(info[1], {});

		plt::suptitle(suptitlestr, keywords);
	}

	void axis(const Napi::CallbackInfo& info) {
		auto axisstr = from<std::string>(info[0], "");

		plt::axis(axisstr);
	}

	void axvline(const Napi::CallbackInfo& info) {
		auto x = from<double>(info[0], 0.0);
		auto ymin = from<double>(info[1], 0.0);
		auto ymax = from<double>(info[2], 0.0);
		auto keywords = from<std::map<std::string, std::string>>(info[3], {});

		plt::axvline(x, ymin, ymax, keywords);
	}

	void xlabel(const Napi::CallbackInfo& info) {
		auto str = from<std::string>(info[0], "");
		auto keywords = from<std::map<std::string, std::string>>(info[1], {});

		plt::xlabel(str, keywords);
	}

	void ylabel(const Napi::CallbackInfo& info) {
		auto str = from<std::string>(info[0], "");
		auto keywords = from<std::map<std::string, std::string>>(info[1], {});

		plt::ylabel(str, keywords);
	}

	void set_zlabel(const Napi::CallbackInfo& info) {
		auto str = from<std::string>(info[0], "");
		auto keywords = from<std::map<std::string, std::string>>(info[1], {});

		plt::set_zlabel(str, keywords);
	}

	void grid(const Napi::CallbackInfo& info) {
		auto flag = from<bool>(info[0], false);

		plt::grid(flag);
	}

	void show(const Napi::CallbackInfo& info) {
		auto block = from<bool>(info[0], true);

		plt::show(block);
	}

	void close(const Napi::CallbackInfo& info) {
		plt::close();
	}

	void xkcd(const Napi::CallbackInfo& info) {
		plt::xkcd();
	}

	void draw(const Napi::CallbackInfo& info) {
		plt::draw();
	}

	void pause(const Napi::CallbackInfo& info) {
		auto interval = from<double>(info[0], 0.0);

		plt::pause(interval);
	}

	void save(const Napi::CallbackInfo& info) {
		auto filename = from<std::string>(info[0], "");

		plt::save(filename);
	}

	void clf(const Napi::CallbackInfo& info) {
		plt::clf();
	}

	void ion(const Napi::CallbackInfo& info) {
		plt::ion();
	}

	void ginput(const Napi::CallbackInfo& info) {
		auto numClicks = from<int>(info[0], 0);
		auto keywords = from<std::map<std::string, std::string>>(info[1], {});

		plt::ginput(numClicks, keywords);
	}

	void tight_layout(const Napi::CallbackInfo& info) {
		plt::tight_layout();
	}
}

Napi::Object init(Napi::Env env, Napi::Object exports) {
	exports.Set(Napi::String::New(env, "backend"), Napi::Function::New(env, matplotnode::backend));
	exports.Set(Napi::String::New(env, "annotate"), Napi::Function::New(env, matplotnode::annotate));
	exports.Set(Napi::String::New(env, "plot"), Napi::Function::New(env, matplotnode::plot));
	exports.Set(Napi::String::New(env, "plot3"), Napi::Function::New(env, matplotnode::plot3));
	exports.Set(Napi::String::New(env, "stem"), Napi::Function::New(env, matplotnode::stem));
	exports.Set(Napi::String::New(env, "fill"), Napi::Function::New(env, matplotnode::fill));
	exports.Set(Napi::String::New(env, "fill_between"), Napi::Function::New(env, matplotnode::fill_between));
	exports.Set(Napi::String::New(env, "hist"), Napi::Function::New(env, matplotnode::hist));
	exports.Set(Napi::String::New(env, "scatter"), Napi::Function::New(env, matplotnode::scatter));
	exports.Set(Napi::String::New(env, "boxplot"), Napi::Function::New(env, matplotnode::boxplot));
	exports.Set(Napi::String::New(env, "bar"), Napi::Function::New(env, matplotnode::bar));
	exports.Set(Napi::String::New(env, "subplots_adjust"), Napi::Function::New(env, matplotnode::subplots_adjust));
	exports.Set(Napi::String::New(env, "named_hist"), Napi::Function::New(env, matplotnode::named_hist));
	exports.Set(Napi::String::New(env, "quiver"), Napi::Function::New(env, matplotnode::quiver));
	exports.Set(Napi::String::New(env, "errorbar"), Napi::Function::New(env, matplotnode::errorbar));
	exports.Set(Napi::String::New(env, "named_plot"), Napi::Function::New(env, matplotnode::named_plot));
	exports.Set(Napi::String::New(env, "named_semilogx"), Napi::Function::New(env, matplotnode::named_semilogx));
	exports.Set(Napi::String::New(env, "named_semilogy"), Napi::Function::New(env, matplotnode::named_semilogy));
	exports.Set(Napi::String::New(env, "named_loglog"), Napi::Function::New(env, matplotnode::named_loglog));
	exports.Set(Napi::String::New(env, "text"), Napi::Function::New(env, matplotnode::text));
	exports.Set(Napi::String::New(env, "figure"), Napi::Function::New(env, matplotnode::figure));
	exports.Set(Napi::String::New(env, "figure_size"), Napi::Function::New(env, matplotnode::figure_size));
	exports.Set(Napi::String::New(env, "legend"), Napi::Function::New(env, matplotnode::legend));
	exports.Set(Napi::String::New(env, "ylim"), Napi::Function::New(env, matplotnode::ylim));
	exports.Set(Napi::String::New(env, "xlim"), Napi::Function::New(env, matplotnode::xlim));
	exports.Set(Napi::String::New(env, "xticks"), Napi::Function::New(env, matplotnode::xticks));
	exports.Set(Napi::String::New(env, "yticks"), Napi::Function::New(env, matplotnode::yticks));
	exports.Set(Napi::String::New(env, "tick_params"), Napi::Function::New(env, matplotnode::tick_params));
	exports.Set(Napi::String::New(env, "subplot"), Napi::Function::New(env, matplotnode::subplot));
	exports.Set(Napi::String::New(env, "subplot2grid"), Napi::Function::New(env, matplotnode::subplot2grid));
	exports.Set(Napi::String::New(env, "title"), Napi::Function::New(env, matplotnode::title));
	exports.Set(Napi::String::New(env, "suptitle"), Napi::Function::New(env, matplotnode::suptitle));
	exports.Set(Napi::String::New(env, "axis"), Napi::Function::New(env, matplotnode::axis));
	exports.Set(Napi::String::New(env, "axvline"), Napi::Function::New(env, matplotnode::axvline));
	exports.Set(Napi::String::New(env, "xlabel"), Napi::Function::New(env, matplotnode::xlabel));
	exports.Set(Napi::String::New(env, "ylabel"), Napi::Function::New(env, matplotnode::ylabel));
	exports.Set(Napi::String::New(env, "set_zlabel"), Napi::Function::New(env, matplotnode::set_zlabel));
	exports.Set(Napi::String::New(env, "grid"), Napi::Function::New(env, matplotnode::grid));
	exports.Set(Napi::String::New(env, "show"), Napi::Function::New(env, matplotnode::show));
	exports.Set(Napi::String::New(env, "close"), Napi::Function::New(env, matplotnode::close));
	exports.Set(Napi::String::New(env, "xkcd"), Napi::Function::New(env, matplotnode::xkcd));
	exports.Set(Napi::String::New(env, "draw"), Napi::Function::New(env, matplotnode::draw));
	exports.Set(Napi::String::New(env, "pause"), Napi::Function::New(env, matplotnode::pause));
	exports.Set(Napi::String::New(env, "save"), Napi::Function::New(env, matplotnode::save));
	exports.Set(Napi::String::New(env, "clf"), Napi::Function::New(env, matplotnode::clf));
	exports.Set(Napi::String::New(env, "ion"), Napi::Function::New(env, matplotnode::ion));
	exports.Set(Napi::String::New(env, "ginput"), Napi::Function::New(env, matplotnode::ginput));
	exports.Set(Napi::String::New(env, "tight_layout"), Napi::Function::New(env, matplotnode::tight_layout));

	return exports;
}

NODE_API_MODULE(matplotlib, init)
