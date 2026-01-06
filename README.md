# cub3D

A raycasting-based 3D game engine written in C, inspired by Wolfenstein 3D. This project implements a first-person perspective game using the DDA (Digital Differential Analyzer) raycasting algorithm.

## Description

cub3D is a 3D graphics project that renders a maze-like environment in first-person perspective. The game reads a `.cub` map file that defines the world layout, textures, and colors, then renders it using raycasting techniques through the MiniLibX graphics library.

## Features

- **Raycasting Engine**: Implemented using DDA algorithm for efficient wall detection
- **Texture Mapping**: Supports custom XPM textures for walls (north, south, east, west)
- **Color Customization**: Configurable floor and ceiling colors (RGB)
- **Player Movement**: Smooth first-person navigation with WASD keys
- **Camera Rotation**: Mouse or arrow key support for looking around
- **Map Validation**: Comprehensive parsing and validation of map files
- **Wall Collision Detection**: Prevents player from walking through walls

## Requirements

- **OS**: Linux (X11)
- **Compiler**: `gcc` or `cc`
- **Libraries**: 
  - X11 development libraries (`libX11-dev`, `libXext-dev`)
  - Math library (`libm`)
  - MiniLibX (included in the repository)

## Building

Compile the project using the provided Makefile:

```bash
make
```

This will:
- Build the MiniLibX library
- Build the libft library (custom C standard library functions)
- Compile all source files
- Create the `cub3D` executable

### Cleanup

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Rebuild everything from scratch
```

## Usage

Run the program with a map file:

```bash
./cub3D maps/good/test.cub
```

The program expects a single argument: the path to a `.cub` map file.

## Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` (Left Arrow) | Rotate camera left |
| `→` (Right Arrow) | Rotate camera right |
| `ESC` | Exit game |

## Map File Format

The `.cub` file must follow this structure:

```
NO <path_to_north_texture.xpm>
SO <path_to_south_texture.xpm>
WE <path_to_west_texture.xpm>
EA <path_to_east_texture.xpm>

F <R,G,B>          # Floor color (RGB values 0-255)
C <R,G,B>          # Ceiling color (RGB values 0-255)

[Map Layout]
```

### Map Layout Rules

- `1` represents a wall
- `0` represents an empty space (walkable)
- `N`, `S`, `E`, `W` represent the player's starting position and initial facing direction:
  - `N` = North (facing up)
  - `S` = South (facing down)
  - `E` = East (facing right)
  - `W` = West (facing left)
- The map must be surrounded by walls (no gaps at borders)
- Only one player spawn position is allowed
- Spaces are allowed outside the map boundaries

### Example Map File

```
NO textures/test/north.xpm
SO textures/test/south.xpm
WE textures/test/west.xpm
EA textures/test/east.xpm

F 20,20,20
C 200,200,200

1             1
1000000000000W1
111111111111111
```

## Project Structure

```
cub3d/
├── exec/           # Game execution and rendering
│   ├── exec.c
│   ├── raycasting.c
│   ├── handle_keys.c
│   ├── handle_moves.c
│   └── ...
├── init/           # Initialization functions
│   ├── init_mlx.c
│   ├── init_state.c
│   ├── init_textures.c
│   └── ...
├── parsing/        # Map file parsing and validation
│   ├── parsing.c
│   ├── is_map_ok.c
│   ├── are_textures_ok.c
│   └── ...
├── libft/          # Custom C library functions
├── mlx/            # MiniLibX graphics library
├── maps/           # Example map files
│   ├── good/       # Valid maps
│   └── bad/        # Invalid maps (for testing)
├── textures/       # Texture resources
├── main.c          # Entry point
├── cub3D.h         # Main header file
└── Makefile        # Build configuration
```

## Configuration

You can modify the following constants in `cub3D.h`:

- `DISPLAY_WIDTH`: Window width (default: 2000)
- `DISPLAY_HEIGHT`: Window height (default: 1400)
- `TEXTURE_SIZE`: Texture dimension (default: 64)
- `ROTATION_SPEED`: Camera rotation speed (default: 0.11)
- `PLAYER_SPEED`: Player movement speed (default: 0.22)

## Technical Details

### Raycasting Algorithm

The engine uses the DDA (Digital Differential Analyzer) algorithm for raycasting:
1. For each vertical column of the screen, a ray is cast from the player's position
2. The ray is traced until it hits a wall
3. The distance to the wall determines the height of the wall slice on screen
4. Textures are mapped to the wall slices based on the hit position

### Rendering Pipeline

1. **Parsing**: Map file is read and validated
2. **Initialization**: MLX window and game state are set up
3. **Game Loop**: 
   - Process user input
   - Update player position
   - Cast rays and render frame
   - Display frame to window

## Example Maps

The `maps/good/` directory contains example maps:
- `test.cub`: Simple test map
- `library.cub`: Library-themed map
- `creepy.cub`: Larger example map

The `maps/bad/` directory contains invalid maps for testing error handling.

## Error Handling

The program validates:
- File extension and format
- Texture file existence and format (must be XPM)
- Color values (valid RGB format)
- Map integrity (walls, player position, connectivity)
- Resource allocation errors
