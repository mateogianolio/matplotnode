(function () {
  'use strict';

  var plt = require('./build/Release/matplotlib');

  var x = new Array(100)
    .fill(0)
    .map((x, i) => i / Math.PI);

  plt.subplot("211");
  plt.plot(x, x.map(Math.sin), 'color=r', 'label=sin(x)');
  plt.plot(x, x.map(Math.cos), 'color=g', 'label=cos(x)');
  plt.legend();

  plt.subplot("212");
  plt.plot(x, x.map(Math.tan), 'color=b', 'label=tan(x)', 'marker=o', 'linestyle=None');
  plt.legend();
  plt.grid(true);
  plt.ylim(-5, 5);

  plt.save("./examples/subplot.png");
}());