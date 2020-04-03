const plt = require('../build/Release/matplotlib');

const x = [];
const y = [];

for (let i = 0; i < 20; i++) {
  x.push(i);
  y.push(i);
}

plt.bar(x, y);
plt.show();

plt.pause();
