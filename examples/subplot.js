const plt = require('../build/Release/matplotlib');

// Prepare data
const n = 500;
const x = Array(n);
const y = Array(n)
const z = Array(n)

for(let i = 0; i < n; ++i) {
  x[i] = i;
  y[i] = Math.sin(2 * Math.PI * i / 360.0);
  z[i] = 100.0 / i;
}

// TODO: fix segfault

// Set the 'super title'
plt.suptitle('My plot');
plt.subplot(1, 2, 1);
plt.plot(x, y, {
  color: 'red',
  linestyle: '-',
});
plt.subplot(1, 2, 2);
plt.plot(x, z, {
  color: 'black',
  linestyle: '-',
});
// Add some text to the plot
plt.text(100, 90, 'Hello!');


// Show plots
plt.show();

plt.pause();
