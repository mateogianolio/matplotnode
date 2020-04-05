{
  "targets": [
    {
      "target_name": "matplotlib",
      "sources": [ "src/matplotlib.cc" ],
      "include_dirs": [
        "<!(python3 -c 'import numpy; print(numpy.get_include())')",
        "<!@(node -p \"require('node-addon-api').include\")",
        "lib"
      ],
      "conditions": [
        ['OS=="mac"', {
          "xcode_settings": {
            "OTHER_CFLAGS": [
              "<!(python3-config --cflags)",
              "-fexceptions"
            ],
            "OTHER_LDFLAGS": [
              "<!(python3-config --ldflags)"
            ]
          }
        }, { # not OSX
          "cflags": [
            "<!(python3-config --cflags)",
            "-fexceptions"
          ]
        }]
      ]
    }
  ]
}
