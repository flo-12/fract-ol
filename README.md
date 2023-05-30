# fract-ol
In mathematics, a fractal is a geometric shape containing detailed structure at arbitrarily small scales, usually having a fractal dimension strictly exceeding the topological dimension. Many fractals appear similar at various scales. Two widely known and used fractals are the Mandelbrot and Julia Fractol.

This program is the first graphical project at 42. It is generating a Mandelbrot or Julia Fractal. It also hooks different key and mouse actions to change certain parameters of the Fractal. For the graphical visualization the 42-school's library MiniLibX is used.
![image](https://github.com/flo-12/fract-ol_project/assets/119588327/5a63b765-cc41-4fc6-a28a-30872306e2ae)

# Usage
*Note that the program is written with Linux. Other operating systems were not tested.*


## Installing and Compiling
1) Clone this repository
2) Clone the [MiniLibX Repo](https://github.com/42Paris/minilibx-linux)
3) ```make``` the MiniLibX (MiniLibX should be afterwards embedded in fract-ol refering to folder and file name in Makefile)
4) ```make``` fract-ol

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

