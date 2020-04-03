const plt = require('../build/Release/matplotlib');

const t = Array(1000);
const x = Array(t.length);

for (let i = 0; i < t.length; i++) {
  t[i] = i / 100.0;
  x[i] = Math.sin(2.0 * Math.PI * 1.0 * t[i]);
}

plt.xkcd();
plt.plot(t, x);
plt.title("AN ORDINARY SIN WAVE");
plt.show();

plt.pause();
