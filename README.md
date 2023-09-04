# fract-ol
In mathematics, a fractal is a geometric shape containing detailed structure at arbitrarily small scales, usually having a fractal dimension strictly exceeding the topological dimension. Many fractals appear similar at various scales. Two widely known and used fractals are the Mandelbrot and Julia Fractol.

This program is the first graphical project at 42. It is generating a Mandelbrot or Julia Fractal. It also hooks different key and mouse actions to change certain parameters of the Fractal. For the graphical visualization the 42-school's library MiniLibX is used.
![Screenshot Julia-Set in red with default values](https://github.com/flo-12/fract-ol/blob/main/Screenshots/Julia_default_red.png)
![Screenshot Mandelbrot-Set in blue](https://github.com/flo-12/fract-ol/blob/main/Screenshots/Mandelbrot_default_blue.png)


# Learning Goals
- create a basic computer graphics project!
- get familiar with the schools' graphical library MiniLibX and using practices like event handling, etc.
- calculating different fract-ols and use the mathematical notion of complex numbers
- How to translate the above points into pure C-code

Core features of the program are:
- render Mandelbrot and Julia set
- handle key and mouse hooks to zoom and move the image
- different color sets for each fractol
- create Julia set of specific point in Mandelbrot

Allowed external functions / libraries:
- open, close, read, write, malloc, free, perror, strerror, exit, printf
- All functions of the math library (-lm compiler option, man man 3 math)
- All functions of the MinilibX - graphical library provided from 42 (see submodule)
- Libft - own library with basic functions such as calloc, strncpm, etc. (see submodule)

 _As usual: All heap allocated memory space must be properly freed. No leaks will be tolerated._


# Usage
*Note that the program is written with Linux. Other operating systems were not tested.*


## Installing and Compiling
1) Clone the repository - and ensure that submodule MiniLibX is cloned as well - by ```git clone --recurse https://github.com/flo-12/fract-ol <folder_name>```
2) direct to the cloned folder ```cd <folder_name>```
4) ```make``` fract-ol (automatically makes MiniLibX for Linux)

*Check the MiniLibX ReadMe in case of problems with the library.*

## Execution
```./fractol <type> <[opt-Julia] C_Re> <[opt-Julia] C_Im> <[opt] max_Iter> <[opt] color>```
* Example: ```./fractol J -0.89 0.42 300 2```

*Note that for the Julia set, the color option will only be available after specifying calculation values ```C_Re``` and ```C_Im```.*

Types are:
* ```M``` or ```Mandelbrot```: Mandelbrot fractol
* ```J``` or ```Julia```: Julia fractol

Optional parameters:
* ```C_Re``` [optional and only for Julia]: real value of Julia set as double (default if not set: -0.79)
* ```C_Im``` [optional and only for Julia]: imaginary value of Julia set as double (default if not set: -0.15)
* ```max_Iter``` [optional]: max amount of Iterations for calculations as int (default if not set: 400
* ```color``` [optional]: color set in the range of 0 and 5 as int )default if not set: 0)

## Fractol controls
While Fractol is running, the following set of controls are available:

| Controls                         | Action                                                        |
|---------------------------------:|:--------------------------------------------------------------|
| ```▲``` ```◄``` ```▼``` ```►```  | Move                                                          |
| ```N```, ```M``` or scroll wheel | Zoom in and out                                               |
| ```A``` or ```D```               | change color                                                  |
| ```W``` or ```S```               | change max Interation                                         |
| ```1```, ```2``` or ```R```      | Switch and reset fractol                                      |
| left click and ```0```           | [Mandelbrot only] get C_Re and C_Im and create refering Julia |
| ```ESC``` or close window        | Quit fract-ol                                                 |

*Note that a feedback to each action is also given in the Terminal.*


# Sources
Realizing this project requires a deeper understanding of the math behind fractals and of the schools graphical library. The following list is a recommendation of sources for anyone who wants to know more about the topic:
| Topic								| Link                                                        	|
|----------------------------------:|:--------------------------------------------------------------|
| General knowledge Fractals	| [Wikipedia-Fractal](https://en.wikipedia.org/wiki/Fractal) |
| General knowledge Fractals (german)	| [Wikipedia-Fractal](https://de.wikipedia.org/wiki/Fraktal) |
| Julia & Mandelbrot set (german) | [theissenonline](http://theissenonline.de/Mathematik/JuliaMandelbrotNeu.pdf) |
| Transformation polar cartesian (german) | [polar coordination system](https://www.lernhelfer.de/schuelerlexikon/mathematik-abitur/artikel/polarkoordinatensystem#) |
| distortion in Mandelbrot | [stackoverflow](https://stackoverflowteams.com/c/42network/questions/1181) |
| Intro & pseudocode | [Computer Graphics Tutorial](https://lodev.org/cgtutor/juliamandelbrot.html) |
| Pseudocode and math Mandelbrot | [Let’s draw the Mandelbrot set!](https://jonisalonen.com/2013/lets-draw-the-mandelbrot-set/) |
| Mathematical description Julia & Mandelbrot | [Understanding Julia and Mandelbrot Sets](http://www.karlsims.com/julia.html) |
| Julia & Mandelbrot intro (german) | [Julia-Mengen und Mandelbrot-Menge](http://theissenonline.de/Mathematik/JuliaMandelbrotNeu.pdf) |
| Intro / Tutorial MiniLibX | [MiniLibX tutorial](https://harm-smits.github.io/42docs/libs/minilibx.html) |
| Intro / Tutorial MiniLibX by Aurelien Brabant | [Getting started with the minilibx](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx) |




