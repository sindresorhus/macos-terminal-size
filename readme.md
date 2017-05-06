# macos-term-size

> Get the terminal window size on macOS

Works even when run [non-interactively](http://www.tldp.org/LDP/abs/html/intandnonint.html), for example, in a child process or when piped.


## Install

[Download](https://github.com/sindresorhus/macos-term-size/releases/latest) the binary and put it in `/usr/local/bin`.


## Usage

```
$ term-size
143
24
```

Where `143` are the number of columns and `24` are the number of rows.


## Comparison

```
$ tput cols
158
$ tput cols &> x; cat x
80
```

```
$ term-size
158
25
$ term-size &> x; cat x
158
25
```


## Build

```
$ ./build
```


## Related

- [term-size](https://github.com/sindresorhus/term-size) - Get the terminal window size, cross-platform *(Uses this binary)*
- [win-term-size](https://github.com/sindresorhus/win-term-size) - Get the terminal window size on Windows


## License

MIT © [Sindre Sorhus](https://sindresorhus.com)
