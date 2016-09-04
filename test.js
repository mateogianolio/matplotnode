(function () {
	'use strict';

	var plt = require('./build/Release/matplotlib');

	var x = new Array(100)
		.fill(0)
		.map((x, i) => i / Math.PI);

	plt.subplot("311");
	plt.plot(x, x.map(Math.sin), 'color=r', 'label=sin(x)');
	plt.legend();

	plt.subplot("312");
	plt.plot(x, x.map(Math.cos), 'color=g', 'label=cos(x)');
	plt.legend();

	plt.subplot("313");
	plt.plot(x, x.map(Math.tan), 'color=b', 'label=tan(x)', 'marker=o', 'linestyle=None');
	plt.legend();
	plt.ylim(-5, 5);

	plt.show();
}());