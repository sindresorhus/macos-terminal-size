# macos-terminal-size

> Get the terminal window size on macOS

Works even when run [non-interactively](http://www.tldp.org/LDP/abs/html/intandnonint.html), for example, in a child process or when piped.

## Install

[Download](https://github.com/sindresorhus/macos-terminal-size/releases/latest) the binary and put it in `/usr/local/bin`.

## Usage

```
$ terminal-size
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
$ terminal-size
158
25
$ terminal-size &> x; cat x
158
25
```

## Build

```sh
./build
```

## Related

- [terminal-size](https://github.com/sindresorhus/terminal-size) - Get the terminal window size, cross-platform
- [windows-terminal-size](https://github.com/sindresorhus/windows-terminal-size) - Get the terminal window size on Windows
