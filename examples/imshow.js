const plt = require('../build/Release/matplotlib');

// Prepare data.
const ncols = 500;
const nrows = 300;
const z = new Float32Array(ncols * nrows);

for (let j = 0; j < nrows; ++j) {
  for (let i = 0; i < ncols; ++i) {
    z[ncols * j + i] = Math.sin(Math.hypot(i - ncols / 2, j - nrows / 2));
  }
}

const colors = 1;
const zptr = z.buffer;

plt.title('My matrix');
plt.imshow(zptr, 11, nrows, ncols, colors);

// Show plots
plt.save('./imshow.png');

console.log('Result saved to "imshow.png"');
