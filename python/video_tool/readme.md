# Grammar

## Example

```plain
// This is a comment.
[video1.mkv]
res 1080p  // output resolution
enc hevc_nvenc  // encoding
3:20 -> 4:15 clip1.mp4  // from -> to name
in 6:25 out 6:30 clip2.mp4  // same
i 1:20:00 o 1:22:04 file name with spaces.mp4

[video2.mkv]
res 1280x720
enc h.264
0 -> 10 clip4.mp4  // 0:0 -> 0:10
in 0:20 time 30s  // in <start> time <duration>
i 1:0 t 2
```

## EBNF

```EBNF
desc = {block}

block = block-head, {line}

block-head = "[", string, "]"

line = {meta-line | clip-line}

meta-line = meta-id, value-list, '\n'

clip-line = {clip-id, value-list} | [clip-abbr], '\n'

value-list = ns-string | ns-string, value-list

ns-string = ns-char, {ns-char}

ns-char = letter | digit | '_'

white-space = {'\n' | ' ' | '\t'}

char = ns-char | white-space

clip-abbr = time-point, "->", time-point, [clip-name]

meta-id = "res" | "enc"

clip-id = "in" | "out" | "time" | "i" | "o" | "t"

time-point = number, ':', number, [':', number]

clip-name = ns-char, {ns-char | ' '}, ns-char

letter = ? [A-Za-z] ?

digit = ? [0-9] ?
```
