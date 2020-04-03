const plt = require('../build/Release/matplotlib');

// Prepare data
const n = 500;
const x = Array(500);
const u = Array(500);
const v = Array(500);
const w = Array(500);

for (let i = 0; i < n; ++i) {
  x[i] = i;
  u[i] = Math.sin(2 * Math.PI * i / 500.0);
  v[i] = 100.0 / i;
  w[i] = Math.sin(2 * Math.PI * i / 1000.0);
}

// TODO: fix segfault

// Set the "super title"
plt.suptitle("My plot");

const nrows = 3;
const ncols = 3;
let row = 2;
let col = 2;

plt.subplot2grid(nrows, ncols, row, col);
plt.plot(x, w, {
  color: 'green',
  linestyle: '-',
});

let spanr = 1;
let spanc = 2;
col = 0;

plt.subplot2grid(nrows, ncols, row, col, spanr, spanc);
plt.plot(x, v, {
  color: 'red',
  linestyle: '-',
});

spanr = 2;
spanc = 3;
row = 0;
col = 0;

plt.subplot2grid(nrows, ncols, row, col, spanr, spanc);
plt.plot(x, u, {
  color: 'blue',
  linestyle: '-',
});

// Add some text to the plot
plt.text(100., -0.5, "Hello!");

// Show plots
plt.show();

plt.pause();
