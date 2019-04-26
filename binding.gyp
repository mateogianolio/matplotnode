{
  "targets": [
    {
      "target_name": "matplotlib",
      "sources": [ "src/matplotlib.cc" ],
      "include_dirs": [
        "<!(python -c 'import numpy; print(numpy.get_include())')"
      ],
      "conditions": [
        ['OS=="mac"', {
            "xcode_settings": {
              "OTHER_CFLAGS": [
                "<!(python-config --cflags)"
              ],
              "OTHER_LDFLAGS": [
                "<!(python-config --ldflags)"
              ]
            }
        }, { # not OSX
          "cflags": [
            "<!(python-config --cflags)"
          ],
          "libraries": [
            "<!(python-config --libs)",
            "-ldl"
          ]
        }]
      ]
    }
  ]
}
