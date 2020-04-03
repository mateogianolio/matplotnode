const plt = require('../build/Release/matplotlib');

const x = [];
const y = [];
const z = [];

let z_inc = 4.0 / 99.0;
let theta_inc = (8.0 * Math.PI) / 99.0;

for (let i = 0; i < 100; i++) {
    const theta = -4.0 * Math.PI + theta_inc * i;
    const r = z[i] * z[i] + 1;
    z.push(-2.0 + z_inc * i);
    x.push(r * Math.sin(theta));
    y.push(r * Math.cos(theta));
}

const keywords = {
  label: 'parametric curve',
};

// TODO: does not look correct... memory problem? conversion problem?

plt.plot3(x, y, z, keywords);
plt.xlabel('x label');
plt.ylabel('y label');
plt.set_zlabel('z label'); // set_zlabel rather than just zlabel, in accordance with the Axes3D method
plt.legend();
plt.show();

plt.pause();
