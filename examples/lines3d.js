const plt = require('../build/Release/matplotlib');

const x = [];
const y = [];
const z = [];

let theta;
let r;
let z_inc = 4.0 / 99.0;
let theta_inc = (8.0 * Math.PI) / 99.0;

for (let i = 0; i < 100; i++) {
    theta = -4.0 * Math.PI + theta_inc * i;
    z.push(-2.0 + z_inc * i);
    r = z[i] * z[i] + 1;
    x.push(r * Math.sin(theta));
    y.push(r * Math.cos(theta));
}

// TODO: does not look correct... memory problem? conversion problem?

plt.plot3(x, y, z, {
  label: 'parametric curve',
});
plt.xlabel('x label');
plt.ylabel('y label');
plt.set_zlabel('z label'); // set_zlabel rather than just zlabel, in accordance with the Axes3D method
plt.legend();
plt.show();
