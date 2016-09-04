# matplotlib for node.js

C++ bindings for Node.js exposing a subset of [matplotlib](http://matplotlib.org/)'s functionality through the [CPython API](https://docs.python.org/2/extending/embedding.html). Inspired by [matplotlib-cpp](https://github.com/lava/matplotlib-cpp) by [lava](https://github.com/lava). Useful for scientific plotting.

### Usage

```bash
$ npm install matplotnode
```

### Bindings

- [x] `plot([x], y, ...kwargs)`*
- [x] `subplot(str)`
- [x] `show()`
- [x] `legend()`
- [x] `grid(bool active)`
- [x] `save(filename)`
- [x] `xlim(from, to)`
- [x] `ylim(from, to)`
- [x] `title(name)`
- [x] `axis(axis)`
- [x] `xlabel(name)`
- [x] `ylabel(name)`

**See how `kwargs` are implemented in `test.js`*