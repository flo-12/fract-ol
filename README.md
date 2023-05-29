# fract-ol
* *General description (1-4 sentences)*

*Note* that the program is written with Linux. Other operating systems were not tested.

# Usage
* *General explenation with MiniLibX and libft*
* *Note that MiniLibX has to be downloaded and installed*

## Installing and Compiling
* *MiniLibX Link and refering to installation Guide*
* *own Makefile with ```make```*

## Execution
```./fractol <type> <[opt-Julia] C_Re> <[opt-Julia] C_Im> <[opt] max_Iter> <[opt] color>```
* Example: ./fractol J -0.89 0.42 300 2
*Please note that for the Julia set, the color option will only be available after specifying calculation values C_Re and C_Im*

Types are:
* M or Mandelbrot: Mandelbrot fractol
* J or Julia: Julia fractol

Optional parameters:
* C_Re [optional and only for Julia]: real value of Julia set as double (default if not set: -0.79)
* C_Im [optional and only for Julia]: imaginary value of Julia set as double (default if not set: -0.15)
* max_Iter [optional]: max amount of Iterations for calculations as int (default if not set: 400
* color [optional]: color set in the range of 0 and 5 as int )default if not set: 0)

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

# Screenshots

# general information a ReadMe contains:
* What the project does? 
* Why the project is useful?
* How users can get started with the project?
* Where users can get help with your project?
* Who maintains and contributes to the project?

# links
Absolut Link: [Link to libft - https://github.com/flo-12/Libft](https://github.com/flo-12/Libft)

Relative Link: [relative Link to Libft - ../../../Libft](../../../Libft)