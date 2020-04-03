const plt = require('../build/Release/matplotlib');

const n = 1000;
const x = [];
const y = [];
const z = [];

for (let i = 0; i < n; i++) {
  x.push(i * i);
  y.push(Math.sin(2 * Math.PI * i / 360.0));
  z.push(Math.log(i));

  if (i % 10 == 0) {
    // Clear previous plot
    plt.clf();
    // Plot line from given x and y data. Color is selected automatically.
    plt.plot(x, y);
    // Plot a line whose name will show up as 'log(x)' in the legend.
    plt.named_plot('log(x)', x, z);

    // Set x-axis to interval [0,1000000]
    plt.xlim(0, n*n);

    // Add graph title
    plt.title('Sample figure');
    // Enable legend.
    plt.legend();
    // Display plot continuously
    plt.pause(0.01);
  }
}
