### Minimal Working Example Showing WASM Safari Bug ###

Updating Emscripten from 1.38.6 to 1.38.31 brought this odd Safari behaviour to light but I don't know which specific version introduced this behaviour.

The pow function returns 0 whenever the exponent is either 1.0 or -1.0. Other values seem
to work as expected.

This was only reproducible only iOS (so it seems to be a WebKit issue). There is already a bug report on WebKit's bugzilla: https://bugs.webkit.org/show_bug.cgi?id=198106

To compile run following command:

`emcc -O2 --bind example.cpp -o example.js`

The result can then be tested on a web server.
