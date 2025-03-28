# cub3D (42Porto - 42Cursus)  

#### Project done in collaboration with [Rodrigo Ramos](https://github.com/ramos21rodrigo)  

### Demonstration  

![](./extras/showcase.gif)

## Description  

Very basic 3D graphical representation of the inside of a maze from a first-person perspective using [Ray casting](https://en.wikipedia.org/wiki/Ray_casting) - introduction to 3D graphics programming.

## Grade: 115/100  

### Installing and running cub3D  

1- Installing dependencies

	sudo apt-get install make xorg libxext-dev zlib1g-dev libbsd-dev
2- Clone this repository:  

	git clone https://github.com/Kuninoto/42_cub3D
3- Compile and clean the object files that you won't need anymore  

	make && make clean
4- Run cub3D with your desired map

	./cub3D <path/to/scene>.cub

### Controls  

	ESC - Quit cub3D
	W A S D / Arrows - Player movement
	Mouse - Move Player's camera 

### Creating new scenes  

	Scene elements:
		'NO' - North texture file path;
		'SO' - South texture file path;
		'EA' - East texture file path;
		'WE' - West texture file path;

		'F' - Floor color in RGB;
		'C' - Ceiling color in RGB;
	Map:
		'0' - Free space;  
		'1' - Wall;  
		'N', 'S', 'E', 'W' - Player's starting position
		(and which coordinate he will be facing at spawn);  

	To be valid, a scene must respect the following:
		- Be in .cub file extension;
		- All textures must be 64x64 and be in XPM format;  
	The map must:
		- Be composed only by valid characters;  
		- Be closed by walls;  
		- Contain only one Player;  
	(You can check examples of valid scenes on /scenes);

#### Makefile available targets  
`make` or `make all` - compiles `cub3D`  
`make clean` - wipes all object files  
`make fclean` - deletes `cub3D` and all object files  
`make re` - `fclean` + `all`  

## NOTES
This project was developed for Linux. Although we've added and decided to  keep conditional compilation and the graphics library for macOS (which do not have some functions that Linux has), it was for development and test purposes only.  

For 42 students:
`mlx_mouse_hide()` has memory leaks product of the mlx library. That's why running this cub3D on a sucessful run with valgrind outputs exactly 28,772 still reachable bytes in 293 blocks.
If you wish to check valgrind without the boycotted memory leakage comment `mlx_mouse_hide()` on line 26 of main.c.  

## Useful links  
[What is Raycasting?](https://en.wikipedia.org/wiki/Ray_casting)  
[Raycasting implementation](https://lodev.org/cgtutor/raycasting.html)  
[MLX documentation](https://harm-smits.github.io/42docs/)  

## Disclaimer  
> At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the "Norm", the schools' coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.

---
Made by Nuno Carvalho (Kuninoto) | nnuno-ca@student.42porto.com  
<div id="badge"> <a href="https://www.linkedin.com/in/nuno-carvalho-218822247"/> <img src="https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn Badge"/>&nbsp;
