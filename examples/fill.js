const plt = require('../build/Release/matplotlib');

// Prepare data.
const theta = [];
for (let d = 0; d < 8 * Math.PI; d += 0.1) {
  theta.push(d);
}

const a = 1;
const b = 0.2;

for (let dt = 0; dt < 2 * Math.PI; dt += Math.PI / 2.0) {
  const x1 = [];
  const y1 = [];
  const x2 = [];
  const y2 = [];

  for (th of theta) {
    x1.push(a * Math.cos(th + dt) * Math.exp(b * th));
    y1.push(a * Math.sin(th + dt) * Math.exp(b * th));

    x2.push(a * Math.cos(th + dt + Math.PI / 4.0) * Math.exp(b * th));
    y2.push(a * Math.sin(th + dt + Math.PI / 4.0) * Math.exp(b * th));
  }

  plt.fill(x1.concat(x2.reverse()), y1.concat(y2.reverse()), {});
}

plt.show();

plt.pause();
