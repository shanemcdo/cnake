# Cnake

## Usage

```
cnake - a snake game written in c
  Usage: cnake [flags]
  Flags:
    -h, --help            Display this message
    -n, --no-loop-walls   Turn off loopable walls
  Controls:
    p - Pause
    Movement:
       w       k       ↑
     a   d   h   l   ←   →
       s       j       ↓
```

## Requirements

- pkg-config
    - Get compile flags for makefile
- ncurses
    - Hide cursor
    - Show cursor
    - Move cursor
    - Print to the screen
    - Clear the screen
    - Restore the screen
