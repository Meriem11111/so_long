# so_long

A small 2D game built in C using the MinilibX graphics library as part of the 42 school curriculum. The player navigates a map, collects all items, and reaches the exit — with an enemy to avoid in the bonus version.

---

## About

so_long is a top-down 2D game rendered tile by tile using `.xpm` sprite images. The map is read from a `.ber` file, validated, and displayed in a window. The player moves with WASD keys, and every move is counted and printed to the terminal.

---

## Features

**Mandatory:**
- Tile-based 2D rendering with custom `.xpm` sprites
- Map validation: border walls, rectangular shape, valid characters, reachability check via flood fill
- Player movement in 4 directions (W/A/S/D)
- Collectible items — door opens only when all are collected
- Move counter printed to the terminal on each step
- Exit on ESC or window close

**Bonus:**
- Enemy character (`N`) that kills the player on contact
- Animated exit door (5-frame `.xpm` animation)
- Move counter displayed directly on the game window

---

## Map Format (`.ber`)

```
11111111111111111
10111000000010111
1P000000C00000111
11111100000000011
100C00000000000E1
11111111111111111
```

**Characters:**
- `1` — wall
- `0` — empty floor
- `P` — player start (exactly 1)
- `E` — exit (exactly 1)
- `C` — collectible (at least 1)
- `N` — enemy (bonus only, at least 1)

**Rules:**
- Map must be fully surrounded by `1`s
- All rows must have equal length
- No empty lines
- All collectibles and the exit must be reachable from the player's starting position (flood fill check)
- Map size: max 52 columns × 27 rows

---

## Controls

| Key | Action |
|-----|--------|
| `W` | Move up |
| `S` | Move down |
| `A` | Move left |
| `D` | Move right |
| `ESC` | Exit game |

---

## Build

```bash
make          # build mandatory version
make bonus    # build bonus version
make clean    # remove object files
make fclean   # remove object files and binary
make re       # full rebuild
```

**Dependencies:** MinilibX (`-lmlx`), OpenGL (`-framework OpenGL`), AppKit (`-framework AppKit`) — macOS build.

---

## Usage

```bash
./so_long maps/map.ber
./so_long maps/mapb.ber   # bonus map with enemy
```

---

## Project Structure

```
so_long/
├── so_long.c         # Entry point, key hooks, window setup
├── so_long.h         # Main header, structs, prototypes
├── check.c           # Map error checking and flood fill
├── check_map.c       # Row/column/character validation
├── game_check.c      # Utility functions, move counter
├── ft_move.c         # Player movement logic
├── load.c            # Sprite loading and window rendering
├── src.c             # Map file reading
├── ft_free.c         # Memory cleanup
├── ft_close.c        # Window destruction and exit
├── bonus/            # Bonus version with enemy and animation
├── textures/         # XPM sprite images
├── maps/             # .ber map files
├── get_next_line/    # GNL for file reading
└── printf/           # Custom ft_printf implementation
```

---

## Requirements

- macOS (uses `-framework OpenGL -framework AppKit`)
- MinilibX
- GCC with C17 support
