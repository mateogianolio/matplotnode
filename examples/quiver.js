const plt = require('../build/Release/matplotlib');

// u and v are respectively the x and y components of the arrows we're plotting
const x = [];
const y = [];
const u = [];
const v = [];

for (let i = -5; i <= 5; i++) {
  for (let j = -5; j <= 5; j++) {
    x.push(i);
    u.push(-i);
    y.push(j);
    v.push(-j);
  }
}

plt.quiver(x, y, u, v);
plt.show();
