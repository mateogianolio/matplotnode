const plt = require('../build/Release/matplotlib');

// Prepare data.
const n = 5000;
const x = Array(5000);
const y = Array(5000);
const z = Array(5000);
const w = Array(5000).fill(2);

for(let i = 0; i < n; ++i) {
  x[i] = i * i;
  y[i] = Math.sin(2 * Math.PI * i / 360.0);
  z[i] = Math.log(i);
}

// Set the size of output image = 1200x780 pixels
plt.figure_size(1200, 780);

// Plot line from given x and y data. Color is selected automatically.
plt.plot(x, y);

// Plot a red dashed line from given x and y data.
plt.plot(x, w,'r--');

// Plot a line whose name will show up as 'log(x)' in the legend.
plt.named_plot('log(x)', x, z);

// Set x-axis to interval [0,1000000]
plt.xlim(0, 1000*1000);

// Add graph title
plt.title('Sample figure');

// Enable legend.
plt.legend();

// save figure
const filename = './basic.png';
console.log(`Saving result to ${filename}`);

plt.save(filename);
