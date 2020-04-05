const plt = require('../build/Release/matplotlib');

// Prepare data.
const n = 5000;
const x = Array(5000);
const y = Array(5000);
const z = Array(5000);

for (let i = 0; i < n; ++i) {
  x[i] = i * i;
  y[i] = Math.sin(2 * Math.PI * i / 360.0);
  z[i] = Math.log(i);
}

// TODO: find out why it crashes if uncommenting alpha: '0.4'?

// Prepare keywords to pass to PolyCollection. See
// https://matplotlib.org/api/_as_gen/matplotlib.axes.Axes.fill_between.html
const keywords = {
  // alpha: '0.4',
  color: 'grey',
  hatch: '-',
};

plt.fill_between(x, y, z, keywords);
plt.show();
