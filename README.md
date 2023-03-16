# cub3D (42Porto - 42Cursus) <img src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg" title="C" alt="C Logo" width="55" height="55" align="right" />&nbsp;  

#### Project done in collaboration with [Rodrigo Ramos](https://github.com/ramos21rodrigo)

## Grade: 115/100

###  Demonstration:

### Installing and running cub3D:
1- Clone this repository:  

	git clone https://github.com/Kuninoto/42_cub3D
2- Navigate to _lvl_4_cub3D_ and run `make`

	cd 42_cub3D/lvl_4_cub3D
	make
3- `make clean` so that you don't keep those object files that you won't need anymore  

	make clean
4- Run cub3D with your desired map

	./cub3D scenes/<map_that_you_want>.cub

###  Subject: [cub3D en_subject](./extras/en.subject_cub3D.pdf)

#### Makefile Available Targets:  
`make` or `make all` - compiles cub3D  
`make clean` - wipes all object files  
`make fclean` - deletes cub3D and all object files  
`make re` - fclean + all  

## NOTES for 42 Students:
mlx_mouse_hide() has memory leaks product of the mlx library, you can't in any way solve them.  
So that's why running this cub3D on a sucessful run with valgrind outputs exactly 28,772 still reachable bytes in 293 blocks.
If you would wish to check valgrind without the boycotted memory leakage comment mlx_mouse_hide() on line 26 of main.c

## Useful links
https://en.wikipedia.org/wiki/Ray_casting  
https://lodev.org/cgtutor/raycasting.html  
https://harm-smits.github.io/42docs/  

## Disclaimer
> At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](./extras/en_norm.pdf), the schools' coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.

---
Made by Nuno Carvalho (Kuninoto) | nnuno-ca@student.42porto.com  
<div id="badge"> <a href="https://www.linkedin.com/in/nuno-carvalho-218822247"/> <img src="https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn Badge"/>&nbsp;
