# So_long

So_long is a 2D game project developed as part of the 42 school curriculum. The game is built using the MinilibX graphics library and focuses on creating a simple yet engaging gaming experience.

## Table of Contents

- [So\_long](#so_long)
  - [Table of Contents](#table-of-contents)
  - [Project Overview](#project-overview)
  - [Features](#features)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Bonus features](#bonus-features)
  - [Project Structure](#project-structure)
  - [Dependencies](#dependencies)
  - [Contributing](#contributing)
  - [License](#license)

## Project Overview

So_long is a 2D game where the player navigates through a map, collecting items and reaching the exit while avoiding obstacles. The game is built using C programming language and the MinilibX graphics library.

## Features

-   2D graphics rendering
-   Player movement (up, down, left, right)
-   Collectible items
-   Exit point
-   Obstacle avoidance
-   Map parsing from .ber files
-   Step counter

## Installation

1. Clone the repository:
   `git clone https://github.com/Dang-Hai-Tran/solong_42.git`
2. Navigate to the project directory:
   `cd solong_42`
3. Compile and run the game:
   `make`

## Usage

Run the game with a map file:
`./so_long maps/<your_map.ber>`

## Bonus features

The bonus version of the project includes additional features:

-   Enemy patrols
-   Animated sprites
-   On-screen step counter

To compile and run the bonus version:
`make bonus`
`./so_long_bonus maps/<your_map.ber>`

## Project Structure

-   `srcs/`: Contains the main source files for the base game
-   `srcs_bonus/`: Contains the source files for the bonus features
-   `includes/`: Header files
-   `libft/`: Custom C library
-   `mlx/`: MinilibX graphics library
-   `maps/`: Sample map files

## Dependencies

-   MinilibX library
-   X11 library
-   Xext library

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
